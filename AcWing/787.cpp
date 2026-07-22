#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), tmp(n);
    for (auto &x: a) {
        cin >> x;
    }

    function<void(int, int)> merge_sort = [&](int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = l + (r - l) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);

        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                tmp[k++] = a[i++];
            } else {
                tmp[k++] = a[j++];
            }
        }

        while (i <= mid) {
            tmp[k++] = a[i++];
        }
        while (j <= r) {
            tmp[k++] = a[j++];
        }

        for (int p = l; p <= r; p++) {
            a[p] = tmp[p];
        }
    };

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
