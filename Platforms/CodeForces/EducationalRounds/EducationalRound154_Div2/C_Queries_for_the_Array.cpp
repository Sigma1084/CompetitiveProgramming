#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    stack<array<int, 2>> st;  // [n, SORTED]

    int n = 0;
    int sorted = 0;  // Number of elements sorted
    for (char c: s) {
        if (c == '+') {
            n += 1;
        } else if (c == '-') {
            while (!st.empty() and st.top()[0] == n) {
                st.pop();
            }
            n -= 1;
            sorted = min(sorted, n);
        } else if (c == '1') {
            if (!st.empty() and st.top()[1] == 0) {
                // Before this unsorted and now sorted impossible
                cout << "NO";
                return;
            }
            sorted = n;
            st.push({n, 1});
        } else if (c == '0') {
            if (sorted == n or n <= 1) {
                // This has to be sorted now
                cout << "NO";
                return;
            }
            st.push({n, 0});
        }
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
