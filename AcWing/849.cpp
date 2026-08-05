#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
    }

    const i64 inf = LLONG_MAX;
    vector<i64> dist(n + 1, inf);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;
        if (u == n) break;

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << (dist[n] == inf ? -1 : dist[n]) << endl;
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