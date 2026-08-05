#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> path(n);
    vector<bool> visited(n + 1, false);

    function<void(int)> dfs = [&](int u)-> void {
        if (u == n) {
            for (int v: path) {
                cout << v << ' ';
            }
            cout << endl;
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            path[u] = i;
            dfs(u + 1);
            visited[i] = false;
        }
    };

    dfs(0);
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
