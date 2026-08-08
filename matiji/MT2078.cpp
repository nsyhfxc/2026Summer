#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

struct Fenwick {
    int n;
    vector<i64> tr;

    Fenwick(int n) : n(n), tr(n + 1, -1) {
    }

    void update(int x, i64 val) {
        for (; x <= n; x += x & -x) {
            tr[x] = max(tr[x], val);
        }
    }

    i64 query(int x) {
        i64 res = -1;
        for (; x; x -= x & -x) {
            res = max(res, tr[x]);
        }
        return res;
    }
};

void solve() {
    i64 v;
    int n, m;
    cin >> v >> n >> m;

    vector<pair<i64, i64> > p;
    p.reserve(n);

    for (int i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
    }

    sort(p.begin(), p.end());

    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = p[i].first;
        b[i] = p[i].second;
    }

    const i64 INF = (1LL << 62);

    auto get = [&](int k) {
        vector<i64> pre(n, INF), suf(n, INF);
        priority_queue<i64> q;
        i64 sum = 0;

        for (int i = 0; i < n; i++) {
            if ((int) q.size() == k) {
                pre[i] = sum;
            }

            q.emplace(b[i]);
            sum += b[i];

            if ((int) q.size() > k) {
                sum -= q.top();
                q.pop();
            }
        }

        q = priority_queue<i64>();
        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            if ((int) q.size() == k) {
                suf[i] = sum;
            }

            q.emplace(b[i]);
            sum += b[i];

            if ((int) q.size() > k) {
                sum -= q.top();
                q.pop();
            }
        }

        return pair{pre, suf};
    };

    i64 ans = -1;

    if (m & 1) {
        int k = m / 2;
        auto [pre, suf] = get(k);

        for (int i = 0; i < n; i++) {
            if (pre[i] == INF || suf[i] == INF) {
                continue;
            }

            if (pre[i] + b[i] + suf[i] <= v) {
                ans = max(ans, 2 * a[i]);
            }
        }
    } else {
        int k = m / 2 - 1;
        auto [pre, suf] = get(k);

        vector<i64> cost;
        cost.reserve(n);

        for (int i = 0; i < n; i++) {
            if (pre[i] != INF) {
                cost.emplace_back(pre[i] + b[i]);
            }
        }

        sort(cost.begin(), cost.end());
        cost.erase(unique(cost.begin(), cost.end()), cost.end());

        Fenwick fw(cost.size());

        for (int q = 0; q < n; q++) {
            int p = q - 1;

            if (p >= 0 && pre[p] != INF) {
                i64 c = pre[p] + b[p];
                int pos = lower_bound(cost.begin(), cost.end(), c) - cost.begin() + 1;
                fw.update(pos, a[p]);
            }

            if (suf[q] == INF) {
                continue;
            }

            i64 lim = v - b[q] - suf[q];
            int pos = upper_bound(cost.begin(), cost.end(), lim) - cost.begin();
            i64 mx = fw.query(pos);

            if (mx != -1) {
                ans = max(ans, mx + a[q]);
            }
        }
    }

    cout << ans / 2 << endl;
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
