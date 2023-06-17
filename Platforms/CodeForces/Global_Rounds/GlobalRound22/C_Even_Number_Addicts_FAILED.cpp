#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int dp[2][4] = {
    { 1, 0, 0, 1 },  // nE = 0
    { 1, 1, 0, 1 }   // nE = 1
};

void solve() {
    int n; cin >> n;
    int nE = 0, nO = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 1) nO++;
        else nE++;
    }

    // Using mutual exchanges
    nO %= 4; nE %= 2;

    // We have 0, 1, 2, 3 Odds and 0, 1 evens
    cout << (dp[nE][nO] == 1 ? "Alice" : "Bob");
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

