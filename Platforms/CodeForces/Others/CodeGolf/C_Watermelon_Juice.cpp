#include <bits/stdc++.h>
using namespace std;
#define l long long

int main() {
    l n, L; cin >> n >> L; l a[n];
    for (l &i: a) cin >> i;
    for (l i = 1; i < n; i++) a[i] = min(2*a[i-1], a[i]);

    l A = 9e18, p = 0;
    do {
        A = min(A, p + a[n-1] * (l)ceil(1.0 * L / (1 << --n)));
        p += a[n] * (L / (1 << n));
        L %= (1 << n);
    } while (L);

    cout << A;
}
