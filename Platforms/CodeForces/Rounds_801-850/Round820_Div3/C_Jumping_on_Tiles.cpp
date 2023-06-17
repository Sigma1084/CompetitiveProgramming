#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<pair<char, int>> x;
    bool rev = false;

    if (s[0] > s[n-1]) {
        rev = true;
        reverse(s.begin(), s.end());
    }

    char m = s[0], M = s[n-1];

    for (int i = 0; i < n; i++) {
        if (s[i] >= m and s[i] <= M) 
            x.push_back({s[i], i});
    }

    sort(x.begin(), x.end());

    cout << M - m << ' ' << x.size() << '\n';
    if (rev) {
        reverse(x.begin(), x.end());
    }

    for (auto &[c, i]: x) {
        if (rev) {
            cout << n - i << ' ';
        } else {
            cout << i + 1 << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

