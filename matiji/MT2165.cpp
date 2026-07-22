#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = n / 2; i; i--) {
        if (s.substr(0, i) == s.substr(i, i)) {
            cout << n - i + 1 << endl;
            return;
        }
    }
    cout << n << endl;
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
