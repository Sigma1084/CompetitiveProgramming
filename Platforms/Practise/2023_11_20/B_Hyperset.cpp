#include <bits/stdc++.h>
using namespace std;

inline string comp(const string &s1, const string &s2) {
    string res;
    res.resize(s1.size());
    for (size_t i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            res[i] = s1[i];
        } else {
            res[i] = 'S' ^ 'E' ^ 'T' ^ s1[i] ^ s2[i];
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (auto &s: a) {
        cin >> s;
    }

    set<string> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string req = comp(a[i], a[j]);
            if (s.count(req)) {
                ++ans;
            }
        }
        s.insert(a[i]);
    }

    cout << ans << '\n';

    return 0;
}
