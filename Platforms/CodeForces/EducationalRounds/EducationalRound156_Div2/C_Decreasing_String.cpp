#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1'000'000;
array<ll, N + 1> tr;

void preCompute() {
    tr[0] = 0;
    for (int i = 1; i <= N; ++i) {
        tr[i] = tr[i-1] + i;
    }
}

void solve() {
    string s; cin >> s;
    ll k; cin >> k;
    auto n = s.size();

    auto j = upper_bound(tr.begin(), tr.end(), tr[n] - k) - tr.begin();
    k -= tr[n] - tr[j];

    // Now, we need to remove and make it equal to j characters
    
    stack<pair<char, int>> st;
    vector<int> ord(n, -1);
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push({s[i], i});
            continue;
        }
        while (!st.empty() and s[i] < st.top().first) {
            // We need to remove prev
            auto [prev, prevId] = st.top();
            ord[prevId] = cur++;
            st.pop();
        }
        st.push({s[i], i});
    }

    while (!st.empty()) {
        // We need to remove prev
        auto [prev, prevId] = st.top();
        ord[prevId] = cur++;
        st.pop();
    }

    for (auto &x: ord) {
        x = n - 1 - x;
    }

    // We have j numbers and we want the kth of it
    string t;
    for (int i = 0; i < n; ++i) {
        if (ord[i] < j) {
            t += s[i];
        }
    }

    cout << t[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCompute();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    cout << endl;

    return 0;
}
