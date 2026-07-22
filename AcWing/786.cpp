#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<i64> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }
    sort(arr.begin(), arr.end());
    cout << arr[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
