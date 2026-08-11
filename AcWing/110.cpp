#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int c, l;
    cin >> c >> l;

    vector<pair<int, int> > cow(c), sun(l);
    for (auto &[mn, mx]: cow) {
        cin >> mn >> mx;
    }
    for (auto &[spf, cov]: sun) {
        cin >> spf >> cov;
    }

    sort(cow.begin(), cow.end());
    sort(sun.begin(), sun.end());

    priority_queue<int, vector<int>, greater<int> > pq;
    int idx = 0;
    int ans = 0;

    for (auto [spf, cov]: sun) {
        while (idx < c && cow[idx].first <= spf) {
            pq.emplace(cow[idx].second);
            ++idx;
        }

        while (!pq.empty() && pq.top() < spf) {
            pq.pop();
        }

        while (cov-- > 0 && !pq.empty()) {
            pq.pop();
            ++ans;
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
