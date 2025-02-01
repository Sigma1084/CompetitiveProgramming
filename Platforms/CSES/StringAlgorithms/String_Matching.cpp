#include <bits/stdc++.h>

std::vector<unsigned int> zFunction(const std::string &s) {
    unsigned int n = static_cast<unsigned int>(s.size());
    std::vector<unsigned int> z(s.size());
    for (unsigned int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, p;
    std::cin >> s >> p;

    using u32 = unsigned int;
    u32 n = static_cast<u32>(s.size()), m = static_cast<u32>(p.size());

    auto z = zFunction(p + '#' + s);
    u32 ans = 0;
    for (u32 i = m + 1; i <= n + m; ++i) {
        if (z[i] == m) {
            ++ans;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
