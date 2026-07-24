#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> arr(n + 1, 0);
    vector<i64> diff(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        diff[i] = arr[i] - arr[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        i64 l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = diff[i] + arr[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
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
