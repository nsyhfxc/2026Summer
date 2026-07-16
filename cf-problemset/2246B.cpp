#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1" << endl;
        return;
    }
    if (n == 2) {
        cout << "-1" << endl;
        return;
    }
    vector<i64> arr(n, 0);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for (int i = 3; i < n; i++) {
        arr[i] = 3 * pow(2,i - 2);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
