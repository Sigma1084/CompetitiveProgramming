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
    int n = s.size();

    auto pi = kmpPrefix(s);
    

    return 0;
}
