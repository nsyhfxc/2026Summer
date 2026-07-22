#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;

    i64 ans = 0;
    for (int len = 1; len < n; len <<= 1) {
        for (int l = 0; l < n; l += len << 1) {
            int m = min(l + len, n);
            int r = min(l + (len << 1), n);
            int i = l, j = m, k = l;

            while (i < m && j < r) {
                if (a[i] <= a[j]) {
                    b[k++] = a[i++];
                } else {
                    b[k++] = a[j++];
                    ans += m - i;
                }
            }
            while (i < m) b[k++] = a[i++];
            while (j < r) b[k++] = a[j++];
        }
        swap(a, b);
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
