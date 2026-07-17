#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    i64 x, y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    for (auto &v: a) {
        cin >> v;
    }
    sort(a.begin(), a.end());
    int mx = 0;
    i64 ans = LLONG_MAX;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        mx = max(mx, j - i);
        i64 cost = a[i] * x + 1LL * (n - j) * y;
        ans = min(ans, cost);
        i = j;
    }
    ans = min(ans, 1LL * (n - mx) * y);
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
}
