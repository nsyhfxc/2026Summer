#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n);
    int mx = 0;
    i64 cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            int pre = i > 0 ? dp[i - 1] : 0;
            int j = i - pre - 1;

            if (j >= 0 && s[j] == '(') {
                dp[i] = pre + 2;
                if (j > 0) {
                    dp[i] += dp[j - 1];
                }
            }
        }

        if (dp[i] > mx) {
            mx = dp[i];
            cnt = 1;
        } else if (dp[i] == mx && mx > 0) {
            cnt++;
        }
    }

    if (mx == 0) {
        cout << "0 1" << endl;
    } else {
        cout << mx << ' ' << cnt << endl;
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
