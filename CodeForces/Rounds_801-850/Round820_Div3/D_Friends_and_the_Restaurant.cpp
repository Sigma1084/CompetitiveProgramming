#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int x, y;

    int numZero = 0;
    vector<int> neg, pos;

    vector<int> X(n), Y(n);
    for (int &i: X) cin >> i;
    for (int &i: Y) cin >> i;

    for (int i = 0; i < n; i++) {
        x = X[i], y = Y[i];
        if (x == y) numZero++;
        else if (x < y) pos.push_back(y - x);
        else neg.push_back(x - y);
    }

    // Neg is when a person wants money
    // Pos is when a person can pay for himself and more
    // numZero is the guys with right amount

    int ans = numZero / 2;
    numZero %= 2;
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    // cout << "Neg: "; for (int &i: neg) cout << i << ' '; cout << '\n';
    // cout << "Pos: "; for (int &i: pos) cout << i << ' '; cout << '\n';

    int p = 0;
    n = 0;
    if (numZero and pos.size()) p++, ans++;

    while (p < pos.size()) {
        if (n < neg.size() and pos[p] >= neg[n]) {
            ans++;
            p++;
            n++;
        } else if (p + 1 < pos.size()) {
            // p + 1 exists
            ans++;
            p += 2;
        } else break;
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

