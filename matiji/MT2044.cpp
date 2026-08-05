#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string s;
    cin >> s;

    int pos = 0, n = s.size();

    function<string()> decode = [&]() -> string {
        string res;

        while (pos < n && s[pos] != ']') {
            if (isupper(s[pos])) {
                res += s[pos++];
            } else {
                ++pos;

                i64 cnt = 0;
                while (pos < n && isdigit(s[pos])) {
                    cnt = cnt * 10 + s[pos++] - '0';
                }

                string cur = decode();
                ++pos;

                while (cnt--) {
                    res += cur;
                }
            }
        }

        return res;
    };

    cout << decode() << endl;
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
