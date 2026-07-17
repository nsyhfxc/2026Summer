#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int k;
    cin >> str;
    cin >> k;
    string str1 = str.substr(k, str.size() - k);
    string str2 = str.substr(0, k);
    cout << str1 << str2 << endl;
    return 0;
}
