#include <bits/stdc++.h>
using namespace std;

int query(const int &a, const int &b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x; return x-1;
}

int recurse(const vector<int> &a) {
    if (a.size() == 2) return a[query(a[0], a[1])];
    vector<int> b;
    for (int i=0; i<a.size(); i+=4) {
        int q = query(a[i], a[i+3]);
        if (q == -1) b.push_back(a[i+1+query(a[i+1], a[i+2])]);
        else b.push_back(a[i+q + 2*(query(a[i+q], a[i+2+q]))]);
    }
    if (b.size() == 1) return b[0];
    else return recurse(b);
}

void solve() {
    int n; cin >> n;
    vector<int> all; for (int i=0; i<pow(2, n); i++) all.push_back(i+1);
    int ans = recurse(all);
    cout << "! " << ans << endl;
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
