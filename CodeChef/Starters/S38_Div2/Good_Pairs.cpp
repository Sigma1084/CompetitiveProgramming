#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }


template <class T>
vi getFreqs(T a[], int n) {
    sort(a, a+n);  // Sort
    vi freqs;

    int currFreq = 1;
    T currEle = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] == currEle)
            currFreq++;
        else {
            freqs.push_back(currFreq);
            currFreq = 1;
            currEle = a[i];
        }
    }
    freqs.push_back(currFreq);
    return freqs;
}


void solve() {
    int n;
    cin >> n;

    int a[n], b[n];
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    // Code starts here
    map <pii, int> opp;
    for (int i=0; i<n; i++) opp[{b[i], a[i]}] += 1;

    ll ansEq = 0;
    ll ansNEq = 0;
    for (auto iter=opp.begin(); iter!=opp.end(); iter++) {
        if (iter->first.first == iter->first.second)
            ansEq += (ll) iter->second * (iter->second - 1) / 2;
        else
            ansNEq += (ll) opp[{iter->first.second, iter->first.first}] * opp[iter->first];
    }

    cout << ansEq + ansNEq/2;

//    ll c[n]; for (int i=0; i<n; i++) c[i] = (ll)(a[i]+b[i]) * 1e9 + (a[i]-b[i]);
//    vi freqs = getFreqs(c, n);
//    ll ans = 0; for (auto i: freqs) ans += (ll) i * (i-1) / 2;
//    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
