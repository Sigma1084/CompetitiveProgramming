#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> proc;
    for (int i = 0; i + m <= n; ++i) {
        if (s.substr(i, m) == t) {
            proc.push_back(i);
        }
    }

    auto isValid = [&](int i) {
        if (i + m > n) {
            return false;
        } else if (s.substr(i, m) == string(m, '#')) {
            return false;
        }
        for (int j = i; j < i + m; ++j) {
            if (s[j] != '#' and s[j] != t[j-i]) {
                return false;
            }
        }
        return true;
    };

    for (int x = 0; x < proc.size(); ++x) {
        int i = proc[x];
        // We are removing s[i] to s[i+m-1]
        std::fill(s.begin() + i, s.begin() + i + m, '#');
        // Now check for previous ones and next ones
        for (int j = max(0, i - m); j < i + m; ++j) {
            if (isValid(j)) {
                proc.push_back(j);
            }
        }
    }

    if (s == string(n, '#')) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
