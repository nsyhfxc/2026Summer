#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
constexpr i64 mod = 1e9 + 7;

void solve() {

    string s;
    cin >> s;

    i64 cnt = 0, ans = 0;
    for (char c: s) {
        if (c == '1') {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = (ans + cnt) % mod;
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
}
