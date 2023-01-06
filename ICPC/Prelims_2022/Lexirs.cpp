#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

string s;

// void recurse(int i, string prevMax, int )

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n); for (auto &x: a) cin >> x;

    int nextDone = -1;
    int done = -1;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B' and i > done) {
            // Do Blue
            if (nextDone < i) {
                cout << -1;
                return;
            } else {
                done = nextDone;
                ans++;
            }
        }
        nextDone = max(nextDone, a[i] + i);
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

