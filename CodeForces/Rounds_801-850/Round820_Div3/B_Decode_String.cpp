#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cur;
    string ans;

    for (int i = 0; i < n; i++) {
        if (i + 2 < n and s[i + 2] == '0') {
            if (i + 3 < n and s[i + 3] == '0') {
                cur = s[i] - '0';
            } else {
                cur = (s[i]-'0')*10 + s[i+1]-'0';
                i += 2;
            }
        } else {
            cur = s[i] - '0';
        }
        ans += (char)(cur + 'a' - 1);
    }

    cout << ans;
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

