#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<string> cup(n + 1);
    unordered_map<string, int> mp;
    mp.reserve(n * 2);

    for (int i = 1; i <= n; i++) {
        cin >> cup[i];
        mp.emplace(cup[i], i);
    }

    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;

        swap(cup[x], cup[y]);
        mp[cup[x]] = x;
        mp[cup[y]] = y;
    }

    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        cout << mp[str] << endl;
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
}
