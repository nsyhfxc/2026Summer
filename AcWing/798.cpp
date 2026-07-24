#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector arr(n + 1, vector<i64>(m + 1));
    vector diff(n + 2, vector<i64>(m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        i64 c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;

        diff[x1][y1] += c;
        diff[x2 + 1][y1] -= c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            cout << arr[i][j] + diff[i][j] << " ";
        }
        cout << endl;
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
