#include<bits/stdc++.h>
using namespace std;
#define L long long

int main() {
    L n, M = 998244353, S = 0;
    cin >> n; L x[n]; for(L &i: x) cin >> i;
    for(L i: x) {
        for (L f = 11; i; f = (f*100) % M, i /= 10)
            S += (i%10) * f; S %= M;
    }
    cout << (S * n) % M;
}
