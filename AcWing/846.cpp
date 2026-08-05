#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > g(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector<int> p(n + 1), ord;
    ord.reserve(n);
    ord.emplace_back(1);

    for (int i = 0; i < n; i++) {
        int u = ord[i];
        for (int v: g[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            ord.emplace_back(v);
        }
    }

    vector<int> sz(n + 1, 1);
    int ans = n;

    for (int i = n - 1; i >= 0; i--) {
        int u = ord[i];
        int mx = n - sz[u];

        for (int v: g[u]) {
            if (p[v] == u) {
                mx = max(mx, sz[v]);
            }
        }

        ans = min(ans, mx);
        if (p[u]) sz[p[u]] += sz[u];
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
