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

    auto m1 = *min_element(a.begin(), a.end());
    vector<int> b;
    for (auto x: a) {
        if (x % m1) {
            b.push_back(x);
        }
    }

    if (b.empty()) {
        cout << "Yes";
        return;
    }

    auto m2 = *min_element(b.begin(), b.end());
    for (auto x: b) {
        if (x % m2) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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
