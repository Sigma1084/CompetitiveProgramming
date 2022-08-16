#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int l, nS; cin >> nS; l = s.size();
    vector<string> a(nS); for (auto &x: a) cin >> x;
    // sort(a.begin(), a.end(), [](string &s1, string &s2) {
    //     return s1.size() >= s2.size();
    // });  // Sort strings in decreasing order of lengths

    vector<int> dp(l+1, INF), prev(l+1), str(l+1), prStr(l+1);

    auto endsWith = [&](const string &s2, const int &p) -> bool {
        // s[p-1] ...  shud match s2[end-1] ... s2[0]
        if (p < s2.size()) return false;
        for (int i=p-1, j=s2.size()-1; j>=0; i--, j--) 
            if (s[i] != s2[j]) return false;
        return true;
    };

    auto update = [&](const int &p, const int &b) -> bool {
        int minI = p;
        for (int i=p-1; i>=p-b; i--) {
            if (dp[i] < dp[minI]) minI = i;
        }
        if (minI == p) return false;
        dp[p] = dp[minI] + 1;
        prev[p] = minI;
        return true;
    };

    dp[0] = 0;
    for (int i=1; i<=l; i++) {
        // Check from start if any string matches
        for (int j=0; j<nS; j++) {
            // Check if the string endsWith a[j]
            if (not endsWith (a[j], i)) continue;
            if (not update (i, a[j].size())) continue;
            str[i] = i - a[j].size() + 1;
            prStr[i] = j+1;
            // cout << a[j] << '\n';
        }
    }

    // for (auto &d: dp) cout << d << ' '; cout << '\n';
    // for (auto &p: prev) cout << p << ' '; cout << '\n';
    // for (auto &st: str) cout << st << ' '; cout << '\n';
    // for (auto &st: prStr) cout << st << ' '; cout << '\n';

    if (dp[l] >= INF) {
        cout << -1;
        return;
    }

    cout << dp[l] << '\n';
    int start, end = l;
    for (int i=1; i <= dp[l]; i++) {
        start = str[end];
        cout << prStr[end] << ' ' << start << '\n';
        end = prev[end];
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

