#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    // int n; cin >> n;
    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> p(10);
    

    for (int i = 0; i < n; i++) {
        p[s[i]-'0'].push_back(i);
    }
    
    string ans;
    string rem;

    int cur = -1;
    for (int i = 0; i < 10; i++) {
        for (auto &x: p[i]) {
            if (x > cur) {
                ans.push_back(i+'0');
                cur = x;
            }
            else {
                rem.push_back(i == 9 ? '9' : i+1+'0');
            }
        }
    }

    ans += rem;
    sort(ans.begin(), ans.end());

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

