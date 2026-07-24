#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int i = 0;
    for (int j = 0, x; j < m; j++) {
        cin >> x;
        if (x == a[i] && i < n) {
            i++;
        }
    }
    if (i == n) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;
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
