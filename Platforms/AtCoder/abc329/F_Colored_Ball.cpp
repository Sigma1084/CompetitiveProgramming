#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<set<int>> s(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s[i].insert(x);
    }

    for (int a, b; nQ--; ) {
        cin >> a >> b;
        --a, --b;
        if (s[a].size() > s[b].size()) {
            swap(s[a], s[b]);
        }
        s[b].insert(s[a].begin(), s[a].end());
        s[a].clear();
        cout << s[b].size() << '\n';
    }

    return 0;
}
