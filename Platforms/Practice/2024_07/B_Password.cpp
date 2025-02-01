#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<unsigned int> zFunction(const std::string &s) {
    unsigned int n = static_cast<int>(s.size());
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

    string s;
    cin >> s;
    unsigned n = s.size();

    auto z = zFunction(s);
    unsigned mx = 0;

    for (unsigned i = 0; i < n; ++i) {
        if (z[i] <= mx and i + z[i] == s.size()) {
            cout << s.substr(0, z[i]) << '\n';
            return 0;
        }
        mx = max(mx, z[i]);
    }

    cout << "Just a legend\n";
    return 0;
}
