#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    auto ask = [n](int u) {
        cout << "? " << u + 1 << endl;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        return d;
    };

    set<pair<int, int>> g;
    auto d0 = ask(0);

    auto numOdds = std::count_if(d0.begin(), d0.end(), 
        [](int x) { return (x % 2) == 1; });
    
    auto d = d0;

    if (numOdds < n - numOdds) {
        // Choose all the odds
        for (int i = 0; i < n; i++) {
            if ((d0[i] % 2) == 0) continue;
            d = ask(i);
            for (int j = 0; j < n; ++j) {
                if (d[j] == 1) {
                    g.insert(minmax(i, j));
                }
            }
        }
    } else {
        // Choose all the evens
        for (int i = 0; i < n; i++) {
            if ((d0[i] % 2) != 0) continue;
            if (i) d = ask(i);
            for (int j = 0; j < n; ++j) {
                if (d[j] == 1) {
                    g.insert(minmax(i, j));
                }
            }
        }
    }

    cout << "!" << endl;
    for (auto [u, v] : g) {
        cout << u + 1 << " " << v + 1 << endl;
    }

    return 0;
}
