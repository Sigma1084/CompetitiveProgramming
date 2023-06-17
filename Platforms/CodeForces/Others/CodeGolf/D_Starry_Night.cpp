#include<bits/stdc++.h>
using namespace std;
#define L long long

int main() {
    L n, i = 0, m = 1e18; cin >> n;
    L x[2*n]; for(L &i: x) cin >> i;;
    sort(x, x + 2*n);
    while(i < n) m = min(m, (x[i+n-1]-x[i]) * (x[2*n-1] - x[i++?0:n]));
    cout << m;
}
