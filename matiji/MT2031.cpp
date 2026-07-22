#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, t;
    cin >> n >> t;
    string str;
    cin >> str;
    while (t--) {
        for (int i = 0; i < n - 1; i++) {
            if (str[i] == 'B' && str[i + 1] == 'G') {
                str[i] = 'G';
                str[i + 1] = 'B';
                i++;
            }
        }
    }
    cout << str << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
}
