#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> pos;
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        int x;
        cin >> x;

        auto it = pos.find(x);
        if (it != pos.end()) {
            l = max(l, it->second + 1);
        }

        pos[x] = r;
        ans = max(ans, r - l + 1);
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
