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
    ll n; int r, M;
    cin >> n >> r >> M;

    {
        int g = __gcd(r, M);
        r /= g;
        M /= g;
    }

    // Code starts here


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    int t;
//    cin >> t;
//
//    while (t--) {
//        solve();
//        cout << "\n";
//    }

    int M = 16;
    int r = 7;
    ll s = 0;
    ll curr = 1;
    for (int i=0; i<18; i++, curr *= r) {
        s += curr;
        cout << s%M << endl;
    }

    return 0;
}
