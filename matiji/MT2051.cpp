#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector pre(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            int x = c - '0';
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        return pre[x2][y2] - pre[x1 - 1][y2]
               - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };

    int ans = 0;

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= m; y2++) {
                    if (get(x1, y1, x2, y2) == 0) {
                        int h = x2 - x1 + 1;
                        int w = y2 - y1 + 1;
                        ans = max(ans, 2 * (h + w));
                    }
                }
            }
        }
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
