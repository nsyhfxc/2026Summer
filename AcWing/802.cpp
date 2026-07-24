#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<i64, i64> > a(n);
    for (auto &[x, c]: a) {
        cin >> x >> c;
    }

    sort(a.begin(), a.end());

    vector<i64> pos(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        pos[i] = a[i].first;
        pre[i + 1] = pre[i] + a[i].second;
    }

    while (m--) {
        i64 l, r;
        cin >> l >> r;

        int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

        cout << pre[R] - pre[L] << endl;
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
