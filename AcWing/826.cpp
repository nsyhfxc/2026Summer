#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

typedef struct Node {
    int x;
    struct Node *next;
} Node;

void solve() {
    int m;
    cin >> m;

    Node *head = new Node{0, nullptr};
    vector<Node *> pos(m + 1);
    pos[0] = head;

    int cnt = 0;

    while (m--) {
        char op;
        cin >> op;

        if (op == 'H') {
            int x;
            cin >> x;

            Node *node = new Node{x, head->next};
            head->next = node;
            pos[++cnt] = node;
        } else if (op == 'D') {
            int k;
            cin >> k;

            Node *pre = pos[k];
            Node *node = pre->next;
            pre->next = node->next;
            delete node;
        } else {
            int k, x;
            cin >> k >> x;

            Node *pre = pos[k];
            Node *node = new Node{x, pre->next};
            pre->next = node;
            pos[++cnt] = node;
        }
    }

    Node *cur = head->next;
    while (cur != nullptr) {
        cout << cur->x << ' ';
        Node *node = cur;
        cur = cur->next;
        delete node;
    }

    delete head;
    cout << endl;
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
