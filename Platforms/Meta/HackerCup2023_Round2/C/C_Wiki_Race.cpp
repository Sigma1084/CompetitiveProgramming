#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> p(n), indeg(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ++indeg[p[i]];
    }

    // Ordering
    vector<int> ord;
    ord.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            ord.push_back(i);
        }
    }
    vector leaves = ord;
    for (int i = 0; i < n; ++i) {
        int u = ord[i];
        if (--indeg[p[u]] == 0) {
            ord.push_back(p[u]);
        }
    }

    // If all leaves have it, then definitley DONE

    vector<int> ms(n);
    vector<set<string>> ws(n);
    // set<string> all;
    for (int i = 0; i < n; ++i) {
        cin >> ms[i];
        string s;
        for (int j = 0; j < ms[i]; ++j) {
            cin >> s;
            ws[i].insert(s);
            // all.insert(s);
        }
    }

    // If something has to be
    // All but 1 leaves must have it

    map<string, int> cnt;
    for (int i = 0; i < n; ++i) {
        for (auto& s: ws[i]) {
            ++cnt[s];
        }
    }

    int ans = 0;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}
