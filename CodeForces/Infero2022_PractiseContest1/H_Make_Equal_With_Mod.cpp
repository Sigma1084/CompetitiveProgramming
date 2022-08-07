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
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    sort(a, a+n);
    int num0, num1, num2;
    int i = 0;
    for (; i<n && a[i]==0; i++);
    num0 = i;
    for (; i<n && a[i]==1; i++);
    num1 = i - num0;
    for (; i<n && a[i]==2; i++);
    num2 = i - num1;

    if (num0 == n || num1 == n || num1 == 0) pY;
    if (num1 > 0 && (num0 > 0 || num2 > 0)) pN;

    // Case when there are 1s and some numbers
    for (int i=0; i<n-1; i++) {
        if (a[i] <= 1) continue;
        if (a[i] + 1 == a[i+1]) pN;
    }
    pY;
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
