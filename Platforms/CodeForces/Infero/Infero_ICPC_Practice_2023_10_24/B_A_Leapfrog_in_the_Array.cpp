#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll q) {
    if (q % 2 == 0) {
        return q / 2 + 1;
    } else {
        return n / 2 + solve((n + 1) / 2, q / 2 + n % 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    int nQ;
    cin >> nQ;

    for (ll p; nQ--; ) {
        cin >> p;
        cout << solve(n, p - 1) << '\n';
    }

    return 0;
}
