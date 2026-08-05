#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

struct Cow {
    i64 w, s;
};

void solve() {
    int n;
    cin >> n;

    vector<Cow> a(n);
    for (auto &[w, s]: a) {
        cin >> w >> s;
    }

    sort(a.begin(), a.end(), [&](const auto &x, const auto &y) {
        return x.w + x.s < y.w + y.s;
    });

    i64 sum = 0;
    i64 ans = LLONG_MIN;

    for (const auto &[w, s]: a) {
        ans = max(ans, sum - s);
        sum += w;
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
