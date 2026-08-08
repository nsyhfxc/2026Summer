#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    vector<i64> nums;
    i64 x;
    while (cin >> x) {
        nums.emplace_back(x);
    }

    i64 ans = 0, cur = 0;
    for (int i = 2; i < (int) nums.size(); i++) {
        i64 d1 = nums[i] - nums[i - 1];
        i64 d2 = nums[i - 1] - nums[i - 2];
        if (d1 == d2) {
            ans += ++cur;
        } else {
            cur = 0;
        }
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
    return 0;
}
