#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int m, n;
    cin >> m >> n;

    cout << 2 * (2*m*n - m - n);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
