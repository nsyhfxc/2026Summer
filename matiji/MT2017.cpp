#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    unordered_map<string, int> mp;
    for (int i = 0; i < n - 1; i++) {
        string temp = str.substr(i, 2);
        mp[temp]++;
    }
    string ans;
    int mx = 0;
    vector<string> v;
    for (const auto &[x,y] : mp) {
        if (y >= mx) {
            mx = y;
        }
    }
    for (const auto &[x,y] : mp) {
        if (y == mx) {
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    cout << *v.begin() << endl;
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
