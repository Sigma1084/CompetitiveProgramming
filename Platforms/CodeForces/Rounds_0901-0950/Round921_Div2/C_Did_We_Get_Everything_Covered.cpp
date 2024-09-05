#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, sN;
    cin >> n >> k >> sN;

    string s;
    cin >> s;

    /// Keep selecting the last character not selected
    set<char> st, stCur;
    for (int i = 0; i < k; ++i) {
        st.insert('a' + i);
    }

    string ans = "";
    int i = 0;
    for (int j = 1; j <= n and i < sN; ++j) {
        stCur = st;
        for (; i < sN; ++i) {
            if (stCur.size() == 1 and s[i] == *stCur.begin()) {
                break;
            }
            stCur.erase(s[i]);
        }
        if (i == sN) break;
        /// s[i] is the last character not selected
        ans.push_back(s[i++]);
    }

    if (ans.size() != n) {
        ans += string(n - ans.size(), *stCur.begin());
        cout << "NO\n" << ans;
    } else {
        cout << "YES";
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
