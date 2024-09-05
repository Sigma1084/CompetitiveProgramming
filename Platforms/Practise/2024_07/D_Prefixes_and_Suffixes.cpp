#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<unsigned int> kmpPrefix(const std::string &s) {
    unsigned int n = static_cast<int>(s.size());
    std::vector<unsigned int> pi(s.size());
    for (unsigned int i = 1, j = 0; i < n; ++i) {
        while (j and s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    unsigned int n = s.size();
    auto pi = kmpPrefix(s);

    vector<int> ans;
    ans.push_back(n);
    while (pi[ans.back() - 1] > 0) {
        ans.push_back(pi[ans.back() - 1]);
    }
    reverse(ans.begin(), ans.end());

    vector<int> occs(n + 1);
    for (int i = 0; i < n; ++i) {
        ++occs[pi[i]];
    }
    for (int i = n - 1; i >= 1; --i) {
        occs[pi[i - 1]] += occs[i];
    }

    cout << ans.size() << '\n';
    for (int x: ans) {
        cout << x << ' ' << 1 + occs[x] << '\n';
    }

    return 0;
}
