#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    map<char, int> cnt;
    for (char c: s) {
        cnt[c]++;
    }

    string cur = "";
    for (auto [c, f]: cnt) {
        cur += c;
    }

    pair<ll, string> ans = {0, ""};

    do {
        string t = s;
        vector<pair<char, int>> beg(cur.size());
        for (int i = 0, k = 0; i < cur.size(); ++i) {
            beg[i] = {cur[i], k};
            k += cnt[cur[i]];
        }
        ll curAns = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &[c, j]: beg) {
                ++j;
                if (t[i] == c) {
                    curAns += j - i - 1;
                    break;
                }
            }
        }
        ans = max(ans, {curAns, cur});
    } while (next_permutation(cur.begin(), cur.end()));

    string ansStr = "";
    for (char c: ans.second) {
        ansStr += string(cnt[c], c);
    }

    cout << ansStr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
