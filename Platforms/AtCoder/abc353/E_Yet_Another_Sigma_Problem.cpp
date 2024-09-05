#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nc2(int n) {
    return 1LL * n * (n - 1) / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    string s;
    stack<int> st;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < int(s.size()) and a[i][j] == s[j]) {
            ++j;
        }
        while (int(st.size()) > j) {
            ans += nc2(i - st.top());
            st.pop();
            s.pop_back();
        }
        while (j < int(a[i].size())) {
            s.push_back(a[i][j]);
            st.push(i);
            ++j;
        }
    }

    while (st.size()) {
        ans += nc2(n - st.top());
        st.pop();
    }

    cout << ans;

    return 0;
}
