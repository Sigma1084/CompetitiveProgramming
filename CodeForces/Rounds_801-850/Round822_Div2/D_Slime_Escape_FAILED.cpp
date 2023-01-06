#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k, cur; cin >> n >> k;
    int bS = k-1, aS = n-k;

    vector<int> b(bS); for (auto &x: b) cin >> x;
    cin >> cur;
    vector<int> a(aS); for (auto &x: a) cin >> x;
    reverse(a.begin(), a.end());

    if (cur < 0) {
        cout << "NO";
        return;
    }

    if (k == 1 or k == n) {
        cout << "YES";
        return;
    }

    // [req, maxPositiveReachable, indexOfMaxPositive]
    vector<tuple<ll, ll, int>> bef(bS + 1);
    vector<tuple<ll, ll, int>> aft(aS + 1);

    for (int i = 1; i <= bS; i++) {
        auto [r, mP, mPI] = bef[i-1];
        r = max(0LL, r - b[i-1]);
        if (mP + b[i-1] >= 0)
            mP += b[i-1];
        else
            mP = 0, mPI = i;
        bef[i] = { r, mP, mPI };
    }

    for (int i = 1; i <= aS; i++) {
        auto [r, mP, mPI] = aft[i-1];
        r = max(0LL, r - a[i-1]);
        if (mP + a[i-1] >= 0)
            mP += a[i-1];
        else
            mP = 0, mPI = i;
        aft[i] = { r, mP, mPI };
    }

    // for (auto &[x, y, z]: bef)
    //     cout << x << ' ' << y << ' ' << z << '\n';
    // for (auto &[x, y, z]: aft)
    //     cout << x << ' ' << y << ' ' << z << '\n';

    int curB = bS, curA = aS;
    while (curB and curA) {
        if (get<0>(aft[curA]) <= cur or get<0>(bef[curB]) <= cur) {
            // We have enough to win
            cout << "YES";
            return;
        }

        if (cur + a[curA-1] < 0 and cur + b[curB-1] < 0) {
            // We can't win no matter what
            cout << "NO";
            return;
        }

        if (curA == get<2>(aft[curA]) and curB == get<2>(bef[curB])) {
            // We can't move at all
            cout << "NO";
            return;
        }

        // Adding both the positives and maximizing cur for the iteration
        cur += get<1>(aft[curA]) + get<1>(bef[curB]);
        curA = get<2>(aft[curA]);
        curB = get<2>(bef[curB]);
    }

    // Now curA = 0 OR curB = 0
    cout << "YES";
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

