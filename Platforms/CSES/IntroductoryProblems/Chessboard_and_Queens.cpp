#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

vector<string> bd(8);
int ans;


void solve() {
    for (auto &x: bd) cin >> x;

    // Brute Force
    // Around 8^8 combinations  => 2^24 =>  1e7

    ans = 0;
    for (int i = 1; i <= 8; i++) {

    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

