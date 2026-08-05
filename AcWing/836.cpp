#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        int rt = x;
        while (fa[rt] != rt) {
            rt = fa[rt];
        }
        while (fa[x] != x) {
            int y = fa[x];
            fa[x] = rt;
            x = y;
        }
        return rt;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == 'M') {
            dsu.merge(a, b);
        } else {
            cout << (dsu.same(a, b) ? "Yes" : "No") << endl;
        }
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
