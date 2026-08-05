#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
constexpr long double eps = 1e-12L;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long double> bal(n + 1), warn(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> bal[i];
    }
    long double ans = 0;
    bool stopped = false;

    for (int i = 0; i < m; i++) {
        int x, y;
        long double z;
        cin >> x >> y >> z;

        if (stopped) {
            continue;
        }

        if (bal[x] + eps < z) {
            stopped = true;
            continue;
        }

        long double stolen = z - floorl(z);

        bal[x] -= z;
        bal[y] += floorl(z);
        warn[y] += stolen;
        ans += stolen;

        if (warn[y] > 1.0L + eps) {
            stopped = true;
        }
    }

    cout << fixed << setprecision(2) << ans + eps << endl;
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
