#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    ll n;
    cin >> n;

    ll count = 0;

    // auto f = [&] () -> void {};
    for (ll i=1; i*i <= n; i++) {
        if (n % i != 0) continue;

        string str = to_string(i);
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (str == rev) count++;

        if (i*i == n) continue;
        
        str = to_string(n/i);
        rev = str;
        reverse(rev.begin(), rev.end());
        if (str == rev) count++;
    }
    
    cout << count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}