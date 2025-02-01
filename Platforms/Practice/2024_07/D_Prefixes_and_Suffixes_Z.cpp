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

    unsigned int n = s.size();
    auto z = zFunction(s);
    z[0] = n;

    vector<int> occ(n + 1);
    vector<int> disp;
    for (int i = n - 1; i >= 0; --i) {
        ++occ[z[i]];
        if (i + z[i] == n) {
            disp.push_back(z[i]);
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        occ[i] += occ[i + 1];
    }

    cout << disp.size() << '\n';
    for (int x: disp) {
        cout << x << ' ' << occ[x] << '\n';
    }

    return 0;
}
