#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    string str;
    getline(cin, str);

    vector<string> arr;
    stringstream ss(str);
    string token;
    int mx = 0;

    while (ss >> token) {
        mx = max(mx, (int) token.size());
        arr.emplace_back(token);
    }

    for (int i = 0; i < mx; i++) {
        string line;

        for (const auto &word: arr) {
            if (i < word.size()) {
                line += word[i];
            } else {
                line += ' ';
            }
        }

        while (!line.empty() && line.back() == ' ') {
            line.pop_back();
        }

        cout << line << endl;
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
