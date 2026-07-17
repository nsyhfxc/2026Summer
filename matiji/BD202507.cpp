#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    i64 s;
    cin >> n >> s;

    i64 ans = s;
    for (int i = 0; i < n; i++) {
        i64 p;
        cin >> p;
        ans = max(ans, (ans + p + 1) / 2);
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
}
