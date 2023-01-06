#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int nD(int n) {
    return (int)log10(1.0 * n) + 1;
}


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), D1(10), D2(10);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while (i < n or j < n) {
        if (i < n and j < n and a[i] == b[j]) i++, j++;
        else if (j == n or (i < n and a[i] < b[j])) {
            if (a[i] > 9) ans++, D1[nD(a[i])]++;
            else D1[a[i]]++;
            i++;
        } else {
            if (b[j] > 9) ans++, D2[nD(b[j])]++;
            else D2[b[j]]++;
            j++;
        }
    }

    for (int i = 2; i <= 9; i++) {
        ans += abs(D1[i] - D2[i]);
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

