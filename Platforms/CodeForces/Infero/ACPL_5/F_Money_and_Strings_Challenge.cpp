#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string t;
    cin >> t;

    int n;
    vector<pair<string, int>> a(n);
    for (auto& [s, c] : a) {
        cin >> s >> c;
    }
    sort(a.begin(), a.end(), [](const auto& l, const auto& r) {
        return l.second < r.second;
    });

    array<int, 26> cnt{};
    for (char c: t) {
        ++cnt[c - 'a'];
    }

    

    return 0;
}
