#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 n, d, l;
    cin >> n >> d >> l;
    i64 s = max(0LL, l - d - 1);
    i64 q = s / d;
    i64 r = s % d;
    i64 mn = q * n + min(r, n) + 1;
    i64 mx = n * (l - n - 1) + 1;
    cout << mn << ' ' << mx << endl;
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
