#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    priority_queue<int> q;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int l = i, r = n - i - 1;
        
        if (s[i] == 'R') ans += r;
        else ans += l;

        if (s[i] == 'R' and r >= l or s[i] == 'L' and l >= r) continue;
        else q.push(abs(l - r));
    }

    for (int i = 0; i < n; i++) {
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        cout << ans << ' ';
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

