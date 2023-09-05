#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Notice that we can sort in odd and even positions
 * If k is even then no use
 * 
 * If k is odd, then 
 * (k + 1) / 2 numbers from even positions go to odd
 * (k + 1) / 2 numbers from odd positions go to even
 */
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (k % 2 == 0 and n > k) {
        sort(s.begin(), s.end());
        cout << s;
        return;
    }

    string a, b;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a += s[i];
        } else {
            b += s[i];
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int l = 0, i = 0, j = 0; l < n; ++l) {
        if (l % 2 == 0) {
            s[l] = a[i++];
        } else {
            s[l] = b[j++];
        }
    }

    if (k % 2 == 0 and n == k) {
        string t = s;
        for (int i = 0; 2*i < n; i++) {
            tie(t[2*i], t[2*i+1]) = tie(t[2*i+1], t[2*i]);
        }
        s = min(s, t);
    }

    cout << s;
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
