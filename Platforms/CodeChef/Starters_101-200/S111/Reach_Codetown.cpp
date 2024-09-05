#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string req = "CODETOWN";

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void solve() {
    string s;
    cin >> s;

    assert(s.size() == 8);

    for (int i = 0; i < 8; ++i) {
        if (isVowel(s[i]) ^ isVowel(req[i])) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
