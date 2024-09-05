#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isBal(const string &s) {
    int cur = 0;
    for (char c: s) {
        if (c == '(') {
            cur += 1;
        } else if (cur == 0) {
            return false;
        } else {
            cur -= 1;
        }
    }
    return true;
}

void mirror(string &s) {
    for (int i = 0, j = int(s.size()) - 1; i < j; ++i, --j) {
        swap(s[i], s[j]);
        s[i] ^= '(' ^ ')';
        s[j] ^= '(' ^ ')';
    }
}

map<string, int> dp;
int dpp(const string &t) {
    if (dp.find(t) != dp.end()) {
        return dp.at(t);
    }
    if (isBal(t)) {
        return dp[t] = 0;
    }
    auto s = t;
    for (int i = 0; i < int(s.size()); ++i) {
        if (s[i] == '(') continue;
        for (int j = i+1; j < int(s.size()); ++j) {
            if (s[j] == ')') continue;
            swap(s[i], s[j]);
            dp[t] = max(dp[t], 1 + dpp(s));
            swap(s[i], s[j]);
        }
    }
    return dp[t];
}

int solve(int n, string &s) {
    if (isBal(s)) {
        return 0;
    }

    int l = 0, r = n - 1;
    while (l < r and s[l] == '(' and s[r] == ')') {
        ++l;
        --r;
    }

    if (s[l] != ')') {
        mirror(s);
    }

    // Ensure s[l] == ')'

    ll ans = 1;
	int lim = n / 2 - l - 1;
    for (int cur = 0, i = n - 1, c = 0; c < lim and i >= 0; --i) {
        if (s[i] == ')') {
            ans += cur;
            c += 1;
        } else {
            ++cur;
        }
    }

    return ans;
}


int main() {
    int lim;
    cin >> lim;

    for (int n = 1; n <= lim; ++n) {
        string s = string(n, '(') + string(n, ')');

        do {
            assert(dpp(s) == solve(2*n, s));
        } while (next_permutation(s.begin(), s.end()));
    }
}