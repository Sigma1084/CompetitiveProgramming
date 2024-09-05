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
    vector<string> as(n);
    for (int i = 0; i < n; ++i) {
        as[i] = to_string(a[i]);
    }

    string s = "0";
    for (int i = 1, l = 0; i < n; ++i) {
        if (a[i] < a[i-1]) {
            while (l < i) {
                if (not is_sorted(as[l].begin(), as[l].end())) {
                    cout << "NO";
                    return;
                }
                if (l and s.back() > as[l].front()) {
                    cout << "NO";
                    return;
                }
                s += as[l++];
            }
        }
        if (a[i] < 10 and as[i][0] < s.back()) {
            cout << "NO";
            return;
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
