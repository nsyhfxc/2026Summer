#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    string stk;
    for (const auto &c: s) {
        while (!stk.empty() && k && stk.back() > c) {
            stk.pop_back();
            k--;
        }
        stk.push_back(c);
    }
    while (k--) {
        stk.pop_back();
    }
    int pos = 0;
    while (pos < stk.size() && stk[pos] == '0') {
        ++pos;
    }
    if (pos == stk.size()) {
        cout << 0 << endl;
        return;
    }
    cout << stk.substr(pos);
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
