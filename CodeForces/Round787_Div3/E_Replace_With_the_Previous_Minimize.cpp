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

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int a[n];
    for (int i=0; i<n; i++)
        a[i] = s[i] - 'a';

    // auto f = [&] () -> void {};
    if (k >= 25) {
        for (int i=0; i<n; i++) cout << 'a';
        return;
    }

    int unable, curMax = 0;
    for (unable=0; unable < n && a[unable] <= k; unable++) 
        curMax = max(curMax, a[unable]);
    
    if (unable == n) {
        for (int i=0; i<n; i++) cout << 'a';
        return;
    }

    // unable < n and that means s[unable] can't be made 'a'

    // Spending curMax amount and making the first unable terms 'a'
    k -= curMax;
    int minAchieve = a[unable] - k;

    string ans = "";
    for (int i=0; i<n; i++) {
        if (a[i] <= curMax)
            ans.pb('a');
        else if (a[i] < minAchieve)
            ans.pb(s[i]);
        else if (a[i] <= a[unable])
            ans.pb('a' + minAchieve);
        else
            ans.pb(s[i]);
    }
    cout << ans;
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
