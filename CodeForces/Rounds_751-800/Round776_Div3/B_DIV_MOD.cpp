#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int lower, upper, a;
    cin >> lower >> upper >> a;

    // Code starts here
    if (lower/a == upper/a) {
        cout << upper/a + upper%a;
        return;
    }

    // Implies upper/a > lower/a
    cout << max(upper/a - 1 + a - 1, upper/a + upper%a);

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
