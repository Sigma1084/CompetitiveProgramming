#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto getSets(const vector<int> &a, int k) {
    int n = int(a.size());
    vector<set<int>> res(k + 1);
    res[0].insert(0);
    for (int i = 0; i < n; ++i) {
        for (int j = min(i, k-1); j >= 0; --j) {
            for (auto x: res[j]) {
                if (x + a[i] < 360) {
                    res[j+1].insert(x + a[i]);
                }
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> t1, t2;
    for (int i = 0; i < n; ++i) {
        int d, t;
        cin >> d >> t;
        if (t == 1) {
            t1.push_back(d);
        } else {
            t2.push_back(d);
        }
    }

    auto r1 = getSets(t1, min(t1.size(), t2.size()));
    auto r2 = getSets(t2, min(t1.size(), t2.size()));

    // for (int i = 0; i <= t1.size(); ++i) {
    //     cerr << i << ": ";
    //     for (auto x: r1[i]) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n';
    // }

    // for (int i = 0; i <= t2.size(); ++i) {
    //     cerr << i << ": ";
    //     for (auto x: r2[i]) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n';
    // }

    for (int i = 1; i <= min(t1.size(), t2.size()); ++i) {
        for (auto x: r1[i]) {
            if (r2[i].count(360 - x)) {
                cout << "Yes";
                return;
            }
        }
    }

    cout << "No";
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
