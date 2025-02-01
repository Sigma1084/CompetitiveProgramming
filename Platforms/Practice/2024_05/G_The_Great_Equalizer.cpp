#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    // Preprocess before handling the queries
    multiset<int> eles, diffs;
    for (auto x: a) {
        eles.insert(x);
    }
    for (auto it = eles.begin(), it2 = next(it); it2 != eles.end(); ++it, ++it2) {
        diffs.insert(*it2 - *it);
    }
    diffs.insert(0);

    // auto debug = [&]() {
    //     cerr << "Eles: ";
    //     for (auto x: eles) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n' << "Diffs: ";
    //     for (auto x: diffs) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n';
    // };

    // debug();
    // cerr << '\n';

    int nQ;
    cin >> nQ;
    while (nQ--) {
        int i, x;
        cin >> i >> x;
        --i;

        // Update the set of elements and differences
        auto it = eles.find(a[i]);
        // Will find the next occurance
        if (it != eles.begin()) {
            diffs.erase(diffs.find(*it - *prev(it)));
        }
        if (next(it) != eles.end()) {
            diffs.erase(diffs.find(*next(it) - *it));
        }
        if (it != eles.begin() and next(it) != eles.end()) {
            diffs.insert(*next(it) - *prev(it));
        }
        eles.erase(it);

        // debug();

        // Insert the new element
        eles.insert(x);
        it = eles.find(x);
        if (it != eles.begin()) {
            diffs.insert(*it - *prev(it));
        }
        if (next(it) != eles.end()) {
            diffs.insert(*next(it) - *it);
        }
        if (it != eles.begin() and next(it) != eles.end()) {
            diffs.erase(diffs.find(*next(it) - *prev(it)));
        }
        a[i] = x;

        // debug();
        // cerr << '\n';

        cout << *diffs.rbegin() + *eles.rbegin() << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
