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

void solve() {
    ll a, b;
    cin >> a >> b;

    // Code starts here
    int d = 40;
    bool light[d], L[d];
    for (int i=0; i<d; i++) {
        light[i] = false;
        L[i] = false;
    }

    if (a < b) {
        cout << a;
        return;
    }

    for (ll c=a, i=0; c>0; c /= 2, i++) {
        if((c&1) == 1)
            light[i] = true;
        else
            light[i] = false;
    }

    for (ll c=b, i=0; c>0; c /= 2, i++) {
        if((c&1) == 1)
            L[i] = true;
        else
            L[i] = false;
    }

    bool hasOvertaken = false;
    for (int i=d-1; i>=0 && !hasOvertaken; i--) {
        if (L[i] && !light[i])
            hasOvertaken = true;
        else if(!L[i] && light[i])
            light[i] = false;
    }

    if (!hasOvertaken) {
        for (int i=0; i<d; i++) {
            if (light[i]) {
                light[i] = false;
                break;
            }
        }
    }

    a = 0;
    for (ll curr=1, i=0; i<d; i++, curr*=2)
        a += light[i] * curr;

    cout << a;
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
