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

bool isPrime(int n) {
    if (n == 2 || n == 3)
        return true;
    for (int i=2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    int b[n];
    for (int i=0; i<n; i++) 
        b[i] = a[i];
    
    sort(a, a+n);

    int Sum = 0;
    for (int i=0; i<n; i++)
        Sum += a[i];
    
    auto printWO = [&](int num) -> void {
        for (int i=0; i<n; i++) {
            if (b[i] == num)
                continue;
            cout << i+1 << " ";
        }
    };

    if (!isPrime(Sum)) {
        cout << n << "\n";
        printWO(-1);
        return;
    }

    for (int i=0; i<n; i++) {
        if (!isPrime(Sum - a[i])) {
            cout << n-1 << "\n";
            printWO(a[i]);
            return;
        }
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
