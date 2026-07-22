#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int pos = 0;
    while (pos + 1 < s.size() && s[pos] == '0') pos++; //去掉前导0
    s = s.substr(pos);
    if (s == "0") {
        cout << 0 << endl;
        return;
    }
    int n = s.size();
    string pal = s;
    for (int i = 0; i < n / 2; i++) {
        pal[n - 1 - i] = pal[i];
    }

    if (pal <= s) {
        cout << pal << endl;
        return;
    }

    int len = (n + 1) / 2;
    string pre = s.substr(0, len);

    int i = len - 1;
    while (i >= 0 && pre[i] == '0') {
        pre[i] = '9';
        i--;
    }
    pre[i]--;

    if (pre[0] == '0') {
        cout << string(n - 1, '9') << endl;
        return;
    }

    string ans = pre;
    int st = n % 2 ? len - 2 : len - 1;

    for (int i = st; i >= 0; i--) {
        ans += pre[i];
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
}
