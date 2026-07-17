#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 l, r;
    cin >> l >> r;
    if (l == r) {
        if (l == 1) cout << 0 << endl;
        else cout << "infty" << endl;
        return;
    }
    i64 d = r - l;
    i64 q = (l - 1) / d;
    i64 ans = (q + 1) * (l - 1) - d * q * (q + 1) / 2;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
