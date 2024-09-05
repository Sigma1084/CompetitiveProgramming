#include <bits/stdc++.h>
using namespace std;

void solve() {
    char a, b; cin >> a >> b;
    int ans = (a-'a') * 25 + (b-'a'+1);
    if (b > a) ans--;
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
