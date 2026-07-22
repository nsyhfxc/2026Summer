#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<i64, vector<pair<int, int> > > pos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            i64 x;
            cin >> x;
            pos[x].emplace_back(i, j);
        }
    }

    i64 ans = 0;

    for (auto &[x, v]: pos) {
        i64 sum = 0;

        // 按照读入顺序，行坐标已经非递减
        for (int i = 0; i < (int) v.size(); i++) {
            ans += 1LL * v[i].first * i - sum;
            sum += v[i].first;
        }

        vector<int> col;
        col.reserve(v.size());

        for (auto &[r, c]: v) {
            col.emplace_back(c);
        }

        sort(col.begin(), col.end());

        sum = 0;
        for (int i = 0; i < (int) col.size(); i++) {
            ans += 1LL * col[i] * i - sum;
            sum += col[i];
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
}
