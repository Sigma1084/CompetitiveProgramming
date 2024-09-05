#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Overload operator<< for vector
template<typename T>
void debug(const vector<T>& v) {
    for (const T& x : v) {
        cerr << x << ' ';
    }
    cerr << '\n';
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> idx;
    int mx = 'a';
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] >= mx) {
            idx.push_back(i);
            mx = s[i];
        }
    }

    // Reverse those indices
    reverse(idx.begin(), idx.end());
    int m = int(idx.size());
    int ans = m;
    for (int i = 0; i < m; ++i) {
        if (s[idx[i]] == s[idx[0]]) {
            --ans;
        } else {
            break;
        }
    }

    for (int i = 0, j = m - 1; i < j; ++i, --j) {
        swap(s[idx[i]], s[idx[j]]);
    }

    if (is_sorted(s.begin(), s.end())) {
        cout << ans;
    } else {
        cout << -1;
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
