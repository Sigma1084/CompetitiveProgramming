#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    int n = int(s.size());
    int nQ;
    cin >> nQ;

    vector<array<int, 26>> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        pref[i][s[i - 1] - 'a']++;
    }

    while (nQ--) {
        int l, r;
        cin >> l >> r;

        if (l == r or s[l-1] != s[r-1]) {
            cout << "Yes\n";
            continue;
        }

        int d = 0;
        for (int i = 0; i < 26; ++i) {
            d += (pref[r][i] - pref[l - 1][i]) > 0;
        }

        if (d > 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
