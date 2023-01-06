#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

string s;
multiset<char> ms;
string pre;

void recurse() {
    if (ms.size() == 1) { cout << pre << *ms.begin() << '\n'; return; }
    // ms.size() > 2
    char pr = '_';
    auto ms_cpy = ms;
    for (auto &c: ms_cpy) {
        if (c == pr) continue;
        pr = c;
        pre.push_back(c); ms.erase(ms.find(c));
        recurse();
        pre.pop_back(); ms.insert(c);
    }
}

void solve() {
    cin >> s;
    for (char &c: s) ms.insert(c);
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int ans = fact[s.size()];
    map<char, int> mp; for (char &c: s) mp[c]++;
    for (auto [c, k]: mp) ans /= fact[k];
    cout << ans << '\n';
    pre = "";
    recurse();
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

