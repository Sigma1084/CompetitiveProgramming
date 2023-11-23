#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Number of 1 digit numbers: 9
 * Number of 2 digit numbers: 90
 * Number of 3 digit numbers: 900
 * ...
 * 
 * 1 digit series: 1 + 2 + 3 + ... + 9 = 45
 * 10 will take 11
 * 11 will take 13
 * Number of digits consumed by a number k:
 * 
 * Sig(k) = 1 + 2 + ... + k
 * f[k] := len(123456789101112...k)
 * f[k] = f[k-1] + len(k)
 * f[1] = 1
 * => f[k] = \Sum_{i=1}^k(len(i))
 * 
 * We will do f(1) f(2) ...
 * Hence,
 * g[k] = g[k-1] + f[k]
 */

constexpr ll A = 1E8;
void solve() {
    ll k;
    cin >> k;

    vector<ll> f, g;
    f.push_back(0);
    g.push_back(0);
    int d = 1;
    ll low = 1, high = 10;
    while (low <= A) {
        for (ll k = low; g.back() < A and k < high; ++k) {
            f.push_back(f.back() + d);
            g.push_back(g.back() + f.back());
        }
        if (g.back() >= A) {
            break;
        }
        low = high;
        high *= 10;
        ++d;
    }
    cerr << "g: ";
    for (int i = 1; i <= 100; ++i) {
        cerr << g[i] << ' ';
    }
    cerr << '\n';

    cerr << "f: ";
    for (int i = 1; i <= 100; ++i) {
        cerr << f[i] << ' ';
    }
    cerr << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
