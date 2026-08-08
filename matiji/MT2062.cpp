#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> pre(n);
    i64 mn = 0;

    for (int i = 1; i < n; i++) {
        i64 q;
        cin >> q;
        pre[i] = pre[i - 1] + q;
        mn = min(mn, pre[i]);
    }

    i64 add = 1 - mn;
    vector<i64> ans(n);
    vector<bool> vis(n + 1);

    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] + add;
        if (ans[i] < 1 || ans[i] > n || vis[ans[i]]) {
            cout << -1 << endl;
            return;
        }
        vis[ans[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
