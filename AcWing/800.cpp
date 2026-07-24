#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    i64 x;
    cin >> n >> m >> x;

    vector<i64> a(n), b(m);
    for (auto &v: a) cin >> v;
    for (auto &v: b) cin >> v;

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        i64 sum = a[i] + b[j];
        if (sum == x) {
            cout << i << ' ' << j << endl;
            return;
        }
        if (sum < x) {
            ++i;
        } else {
            --j;
        }
    }
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
