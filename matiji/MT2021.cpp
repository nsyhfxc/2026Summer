#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 n, m, s;
    cin >> n >> m >> s;

    auto calc = [&](i64 x) {
        i64 q = x / s, r = x % s;
        return r ? r * (q + 1) : x;
    };

    cout << calc(n) * calc(m) << endl;
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
