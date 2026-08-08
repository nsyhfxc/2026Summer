#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
void solve() {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> bad(n + 1);
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        bad[x] = 1;
    }

    int cur = 0;
    for (int i = 1; i <= k; i++) {
        cur += bad[i];
    }

    int ans = cur;
    for (int l = 2, r = k + 1; r <= n; l++, r++) {
        cur += bad[r] - bad[l - 1];
        if (cur < ans) {
            ans = cur;
        }
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}