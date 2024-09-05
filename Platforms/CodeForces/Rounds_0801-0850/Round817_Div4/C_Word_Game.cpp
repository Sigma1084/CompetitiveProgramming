#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<string, vector<int>> f;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        f[s].push_back(1);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        f[s].push_back(2);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        f[s].push_back(3);
    }

    vector<int> ans(4);

    for (auto &[w, o]: f) {
        if (o.size() == 1) {
            ans[o[0]] += 3;
        } else if (o.size() == 2) {
            ans[o[0]] += 1;
            ans[o[1]] += 1;
        }
    }

    cout << ans[1] << ' ' << ans[2] << ' ' << ans[3];
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

