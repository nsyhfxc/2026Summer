#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
constexpr i64 mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    i64 pre;
    cin >> pre;
    bool hasNeg = pre == -1;
    int d = 1, cnt = 0;
    for (int i = 1; i < n; i++) {
        i64 x;
        cin >> x;
        if (x != pre) {
            d++;
            if (pre > 0 && x == pre + 1) {
                cnt++;
            }
        }
        pre = x;
    }
    i64 ways = 1;
    for (int i = 0; i < n - d; i++) {
        ways = ways * 2 % mod;
    }
    i64 ans = ways * (1 + (hasNeg ? cnt : 0)) % mod;
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
