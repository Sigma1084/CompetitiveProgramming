#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> a;
    int cur = 2;
    for (char c: s) {
        if (c - '0' == cur) {
            a.back()++;
        } else {
            a.push_back(1);
            cur = c - '0';
        }
    }

    int m = int(a.size());

    int i = 0;
    for (; i < m; ++i) {
        if (a[i] != k) {
            break;
        }
    }
    for (int j = i + 1; j + 1 < m; ++j) {
        if (a[j] != k) {
            cout << -1;
            return;
        }
    }

    if (i == m) {
        cout << n;
    } else if (i == m - 1) {
        cout << -1;
    } else if (a[i] < k) {
        if ((m - 1 - i) % 2 == 0) {
            if (a[i] + a.back() == k) {
                cout << k * i + a[i];
            } else {
                cout<< -1;
            }
        } else {
            cout << -1;
        }
    } else {
        if ((m - 1 - i) % 2 == 0) {
            if (a[i] - k + a.back() == k) {
                cout << k * i + a[i] - k;
            } else {
                cout << -1;
            }
        } else {
            if (a[i] == 2*k and a.back() == k) {
                cout << k * i + k;
            } else {
                cout << -1;
            }
        }
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
