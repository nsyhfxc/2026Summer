#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void solve() {
    int n, m;
    cin >> n >> m;

    vector grid(n, vector<int>(m));
    vector dist(n, vector(m, -1));

    for (auto &row: grid) {
        for (auto &x: row) {
            cin >> x;
        }
    }

    queue<pair<int, int> > q;
    q.emplace(0, 0);
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (grid[nx][ny] == 1 || dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    cout << dist[n - 1][m - 1] << endl;
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
