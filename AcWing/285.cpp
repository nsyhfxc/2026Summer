#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    vector<vector<int> > g(n + 1);
    vector<int> fa(n + 1);

    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        g[k].emplace_back(l);
        fa[l] = k;
    }

    int root = 1;
    while (fa[root]) {
        root = fa[root];
    }

    vector<array<i64, 2> > dp(n + 1);

    function<void(int)> dfs = [&](int u) {
        dp[u][1] = h[u];

        for (int v: g[u]) {
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };

    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
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
