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

    // Can't have more than 3 negatives or positives
    int pos = 0, neg = 0, z = 0;
    vector<int> b;
    for (int x: a) {
        if (x > 0) {
            if (pos == 2) {
                cout << "NO";
                return;
            }
            ++pos;
            b.push_back(x);
        } else if (x < 0) {
            if (neg == 2) {
                cout << "NO";
                return;
            }
            ++neg;
            b.push_back(x);
        } else {
            if (z < 2) {
                ++z;
                b.push_back(x);
            } else {
                ++z;
            }
        }
    }

    // Brute force over b
    n = int(b.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int s = b[i] + b[j] + b[k];
                bool ok = false;
                for (int x: b) {
                    if (s == x) {
                        ok = true;
                        break;
                    }
                }
                if (not ok) {
                    cout << "NO";
                    return;
                }
            }
        }
    }

    cout << "YES";
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
