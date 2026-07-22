#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    while (q--) {
        int k;
        cin >> k;

        auto l = lower_bound(a.begin(), a.end(), k) - a.begin();

        if (l == n || a[l] != k) {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }

        auto r = upper_bound(a.begin(), a.end(), k) - a.begin() - 1;
        cout << l << ' ' << r << endl;
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
