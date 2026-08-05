#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (auto &x: h) {
        cin >> x;
    }

    vector<int> l(n, 1), r(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (h[j] > h[i]) {
                l[i] = max(l[i], l[j] + 1);
            }
        }
        ans = max(ans, l[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (h[j] > h[i]) {
                r[i] = max(r[i], r[j] + 1);
            }
        }
        ans = max(ans, r[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
