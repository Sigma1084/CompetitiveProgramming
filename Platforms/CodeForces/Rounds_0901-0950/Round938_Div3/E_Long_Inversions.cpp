#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int k = n; k >= 2; --k) {
        string t = s;
        deque<int> q;
        for (int i = 0; i <= n - k; ++i) {
            if (q.size() and q.front() + k == i) {
                q.pop_front();
            }
            if (q.size() & 1) {
                t[i] ^= '1' ^ '0';
            }
            if (t[i] == '0') {
                q.push_back(i);
                t[i] = '1';
            }
        }
        bool ok = true;
        for (int i = n - k + 1; i < n; ++i) {
            if (q.size() and q.front() + k == i) {
                q.pop_front();
            }
            if (q.size() & 1) {
                t[i] ^= '1' ^ '0';
            }
            if (t[i] == '0') {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << k;
            return;
        }
    }

    cout << 1;
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
