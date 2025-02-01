#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    for (auto &c: s) {
        if (c >= '5') {
            c = '0' + 9 - (c - '0');
        }
    }

    if (s[0] == '0') {
        s[0] = '9';
    }

    cout << s;
    return 0;
}
