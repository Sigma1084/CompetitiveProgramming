#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    string ans = s;
    for (int i = 0; i < n; i++) {
        string t = s.substr(i) + s.substr(0, i);
        // Now reduce these strings
        int rem = 10 - (t[0] - '0');

        // Reduce every digit by rem
        for (int j = 0; j < n; j++) {
            t[j] = '0' + (t[j] - '0' + rem) % 10;
        }
        ans = min(ans, t);
    }

    cout << ans;

    return 0;
}
