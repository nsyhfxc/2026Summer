#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt[3] = {0};

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int sum = 0;
        for (const auto &c : str) {
            sum += c - '0';
        }

        cnt[sum % 3]++;
    }

    int ans = 0;
    ans += cnt[0] / 2;
    ans += min(cnt[1], cnt[2]);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}