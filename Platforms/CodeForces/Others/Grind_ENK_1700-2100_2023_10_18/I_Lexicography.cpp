#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, len, k;
    cin >> n >> len >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int sP = 0;

    vector<string> words(n);
    for (auto &w: words) {
        w.reserve(len);
    }
    for (int l = 0, j = 0; l < len; ++l) {
        for (int i = j; i < k; ++i) {
            words[i].push_back(s[sP++]);
            if (i > j and words[i].back() != words[i-1].back()) {
                j = i;
            }
        }
    }

    for (auto &w: words) {
        while (w.size() < len) {
            w.push_back(s[sP++]);
        }
    }

    for (const auto &w: words) {
        cout << w << '\n';
    }

    return 0;
}
