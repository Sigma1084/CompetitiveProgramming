#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string a[n][2];

    for (int i=0; i<n; i++)
        cin >> a[i][0] >> a[i][1];

    // Code starts here
    bool status[n];
    for (int i=0; i<n; i++)
        status[i] = false;

    auto isPresent = [&](string s, int lim)->int {
        for (int i=0; i<lim; i++) {
            if (a[i][status[i]] == s)
                return true;
        }
        return false;
    };

    for (int i=0; i<n; i++) {
        if (isPresent(a[i], i)) {

        }
    }
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
