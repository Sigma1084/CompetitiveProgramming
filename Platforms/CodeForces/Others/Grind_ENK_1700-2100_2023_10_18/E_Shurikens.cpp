#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    stack<pair<int, int>> prev;  // [a, prevSz]
    prev.emplace(0, 0);

    vector<int> ans(n);
    for (int i = 0, j = 0; i < 2*n; ++i) {
        char t;
        cin >> t;

        if (t == '+') {
            st.push(j++);
        } else {
            int x;
            cin >> x;

            // Everything in the stack must be greater than x
            if (st.empty()) {
                cout << "NO";
                return 0;
            }

            auto [a, prevSz] = prev.top();
            if (st.size() == prevSz and x < a) {
                cout << "NO";
                return 0;
            } else if (st.size() == prevSz) {
                prev.pop();
            }

            auto idx = st.top(); st.pop();
            ans[idx] = x;

            // If we have another specification
            if (!prev.empty() and prev.top().second == st.size()) {
                tie(a, prevSz) = prev.top();
                a = max(a, x);
                prev.pop();
                prev.emplace(a, prevSz);
            } else {
                prev.emplace(x, st.size());
            }
        }
    }

    cout << "YES\n";
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
