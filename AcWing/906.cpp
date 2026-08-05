#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int> > event;
    event.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        event.emplace_back(a, 0);
        event.emplace_back(b, 1);
    }

    sort(event.begin(), event.end());

    int cnt = 0, ans = 0;
    for (auto [x, type]: event) {
        if (type == 0) {
            ans = max(ans, ++cnt);
        } else {
            --cnt;
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
