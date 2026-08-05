#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<string> g(n, string(n, '.'));
    vector<bool> col(n), dg(2 * n), udg(2 * n);

    function<void(int)> dfs = [&](int r) {
        if (r == n) {
            for (const auto &row: g) {
                cout << row << endl;
            }
            cout << endl;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || dg[r - c + n] || udg[r + c]) {
                continue;
            }

            g[r][c] = 'Q';
            col[c] = dg[r - c + n] = udg[r + c] = true;

            dfs(r + 1);

            g[r][c] = '.';
            col[c] = dg[r - c + n] = udg[r + c] = false;
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
