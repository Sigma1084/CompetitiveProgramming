#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define pb push_back

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // Returns 0 for '1' and 1 for '0'
    auto rev = [&] (char c) -> int {return (c-'0') ^ 1;};

    int f[n];

    // We know that the sum of all should be k
    int rem = k;

    // Whether the characters retain without changing
    bool swap = k%2;

    for (int i=0; i<n; i++) {
        if (rem == 0) {
            f[i] = 0;
            if (swap)
                cout << rev(s[i]);
            else
                cout << s[i];
            continue;
        }

        if (i == n-1) {
            f[n-1] = rem;
            rem = (rem + retain) % 2;
            if (rem)
                cout << 1;
            else
                cout << 0;
            continue;
        }

        // Here, rem is not 0
        if (!swap) {
            if (s[i] == 1) {
                f[i] = 0;
                cout << 1;
            }
            else {
                f[i] = 1;
                rem--;
                cout << 1;
            }
        }

        else {
            if (s[i] == 0) {
                f[i] = 0;
                cout << 1;
            }
            else {
                f[i] = 1;
                rem--;
                cout << 1;
            }
        }
    }

    cout << endl;
    for (int i=0; i<n; i++) {
        cout << f[i] << " ";
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
