#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> b(n); for (auto &x: b) cin >> x;
    a.push_back(a.front()); b.push_back(b.front());

    for (int i = 0; i < n; i++) {
        if ((a[i] > b[i]) or a[i] < b[i] and b[i] > b[i+1] + 1) 
        { cout << "NO"; return; }
    }

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

