#include <bits/stdc++.h>
using namespace std;

/**
 * Remove the leaves and give and add 1 to paren't score
 * If a node's score is ever 2, then REMOVE it
 */

void solve() {
    int n;
    cin >> n;

    vector<int> deg(n);
    vector<set<pair<int, int>>> e(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u]; ++deg[v];
        e[u].emplace(v, i);
        e[v].emplace(u, i);
    }

    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(deg[i], i);
    }

    vector<int> ans;
    vector<int> score(n);
    
    auto debug = [&] () {
        cerr << "deg: ";
        for (int i = 0; i < n; ++i) {
            cerr << deg[i] << ' ';
        }
        cerr << '\n';

        cerr << "score: ";
        for (int i = 0; i < n; ++i) {
            cerr << score[i] << ' ';
        }
        cerr << '\n';

        cerr << "e: \n";
        for (int i = 0; i < n; ++i) {
            cerr << i << ": ";
            for (auto [v, eIdx]: e[i]) {
                cerr << v << ' ';
            }
            cerr << '\n';
        }
        cerr << '\n';
    };

    while (!s.empty()) {
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        // We need to remove this node now
        if (d == 0) {
            assert(s.empty());
            if (score[u] != 2) {
                cout << -1;
                return;
            } else {
                break;
            }
        }
        assert(d == 1);

        // Remove this node
        auto [p, eIdx] = *e[u].begin();
        e[p].erase({u, eIdx});
        e[u].erase({p, eIdx});
        s.erase({deg[p], p});
        --deg[p]; --deg[u];
        s.emplace(deg[p], p);

        // Add this node to answer if required
        if (score[u] == 2) {
            ans.push_back(eIdx);
            continue;
        }

        // Feasibility
        if (score[u] == 0 and score[p] < 2) {
            score[p] += 1 + score[u];
        } else if (score[u] == 1 and score[p] < 1) {
            score[p] += 1 + score[u];
        } else {
            cout << -1;
            return;
        }
    }

    cout << ans.size() << '\n';
    for (int x: ans) {
        cout << x + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
