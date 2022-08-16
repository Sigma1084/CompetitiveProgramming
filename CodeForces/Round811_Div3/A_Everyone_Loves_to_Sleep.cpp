#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    int h, m, s; cin >> h >> m; s = 60 * h + m;

    vector<int> times(n);
    for (auto &t: times) {
        cin >> h >> m;
        t = 60*h + m;
    }
    sort(times.begin(), times.end());

    int x;
    auto it = lower_bound(times.begin(), times.end(), s);
    if (it != times.end()) x = *it;
    else x = *times.begin() + 24*60;
    x -= s;
    h = x / 60;
    m = x % 60;

    cout << h << ' ' << m;
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

