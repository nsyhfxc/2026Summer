#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    i64 sum = 0;
    for (auto &x: a) {
        cin >> x;
        sum += x;
    }

    i64 avg = sum / n;
    i64 pre = 0, ans = 0;

    for (int i = 0; i < n - 1; i++) {
        pre += a[i] - avg;
        ans += abs(pre);
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
