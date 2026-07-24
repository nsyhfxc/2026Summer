#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<i64, i64> > a(n);
    for (auto &[l, r]: a) {
        cin >> l >> r;
    }

    sort(a.begin(), a.end());

    int ans = 1;
    i64 r = a[0].second;

    for (int i = 1; i < n; i++) {
        if (a[i].first <= r) {
            r = max(r, a[i].second);
        } else {
            ans++;
            r = a[i].second;
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
