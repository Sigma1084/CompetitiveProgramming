#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    // Code starts here
    int possible = 0;
    int steps = 0;
    for (int d=1; n > possible; d++) {
        steps += d * min(d*4, n-possible);
        possible += d*4;
    }
    cout << steps;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
