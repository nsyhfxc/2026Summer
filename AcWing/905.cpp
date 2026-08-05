#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr[i] = {r, l};
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    i64 p = LLONG_MIN;
    for (auto [r, l]: arr) {
        if (p < l) {
            p = r;
            ans++;
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
