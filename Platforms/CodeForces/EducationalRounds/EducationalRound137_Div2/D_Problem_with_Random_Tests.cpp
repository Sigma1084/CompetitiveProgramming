#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int firstOne = 0;
    for (; firstOne < n and s[firstOne] == '0'; firstOne++);

    if (firstOne == n) {
        // No ones
        cout << 0;
        return;
    }

    int firstZero = firstOne + 1;
    for (; firstZero < n  and s[firstZero] == '1'; firstZero++);

    if (firstZero == n) {
        // No zeroes
        for (int i = firstOne; i < n; i++) cout << s[i];
        return;
    }

    string ans = s, bot = s, temp;
    for (int i = firstOne; i <= firstZero; i++, bot = '0' + bot) {
        temp = s;
        for(int j = 0; j < n; j++)
            if (bot[j] == '1') temp[j] = '1';
        ans = max(ans, temp);
    }

    for (int i = firstOne; i < n; i++)
        cout << ans[i];
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

