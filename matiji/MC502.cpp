#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int z = 0,f = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) f++;
        else if (x > 0) z++;
    }
    cout << z << " " << f << endl;
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