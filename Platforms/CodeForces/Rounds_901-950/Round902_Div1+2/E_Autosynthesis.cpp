#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }

    vector<set<int>> rev(n);
    for (int i = 0; i < n; i++) {
        rev[a[i]].insert(i);
    }

    // [inDeg[u], u]
    set<pair<int, int>> s;
    for (int u = 0; u < n; ++u) {
        s.insert({rev[u].size(), u});
    }

    vector<bool> rem(n, false);
    vector<int> ans;
    while (!s.empty()) {
        auto [inDeg, u] = *s.begin();

        if (inDeg == 0) {
            ans.push_back(u);
            rem[u] = true;
            s.erase(s.begin());

            if (rem[a[u]]) continue;

            // We need to remove a[u] from the set
            rem[a[u]] = true;
            s.erase({rev[a[u]].size(), a[u]});

            // We need to reduce the indegree of a[a[u]] by 1
            int v = a[a[u]];
            if (rem[v]) continue;

            s.erase({rev[v].size(), v});
            rev[v].erase(a[u]);
            s.insert({rev[v].size(), v});

            continue;
        }

        // Now it is a cycle
        assert(inDeg == 1);

        // Find the length of the cycle
        int v = a[u], l = 1;
        bool oddRem = false, evenRem = false;
        while (v != u) {
            if (l % 2 == 0) evenRem |= rem[v];
            else oddRem |= rem[v];
            v = a[v];
            ++l;
        }

        // Odd cycle or remove everything in an even cycle
        if (l % 2 or (evenRem and oddRem)) {
            cout << -1;
            return;
        }

        if (!evenRem and !oddRem) {
            oddRem = true;
        }

        v = u, l = 0;
        do {
            if (evenRem and l % 2 == 0 and !rem[v]) {
                ans.push_back(v);
            } else if (oddRem and l % 2 and !rem[v]) {
                ans.push_back(v);
            }
            rem[v] = true;
            s.erase({rev[v].size(), v});
            v = a[v];
            ++l;
        } while (v != u);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int x: ans) {
        cout << a[x] + 1 << ' ';
    }

    return 0;
}