#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    int orders[n];

    // Code starts here
    int start = 0;
    for (int i=n; i>=1; i--) {
        int j;
        int count = 0;
        for (j=0; j<n; j++) {
            if (a[(j+start)%n] > i)
                continue;
            if (a[(j+start)%n] == i) {
                orders[i-1] = (count+1)%i;
                start = (j+start+1)%n;
                break;
            }
            count++;
        }
    }

    for (int i: orders) {
        cout << i << " ";
    }
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
