#include <bits/stdc++.h>
using ll = long long;
constexpr int P = 1000000007;

ll modPow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = a*a % P) {
        if (b & 1) {
            r = r*a % P;
        }
    }
    return r;
}

ll modDiv(ll a, ll b) {
    return a * modPow(b, P - 2) % P;
}

int main() {
    int n, m;
    std::cin >> n;
    m = n;
    
    if (n > m) std::swap(n, m);  // Ensure n <= m

    /**
     * firstEle = 1 for 0 <= r <= m and rCm for m <= r <= m+n \n
     * lastEle = 1 for 0 <= r <= n and rCn for n <= r <= m+n
     *
     * We now know that the first and last elements are 1 or
     * of the form rCm and rCn respectively.
     *
     * We can use the below formula to recursively calculate
     * the next elements of the form nCk \n
     * nCk = (n-1)Ck * n/(n-k)  ==>  ele *= n/(n-k)
     */

    ll ans = 1, rowSum = 1, firstEle = 1, lastEle = 1;

    // For the first n rows, we do not subtract anything
    for (int r = 1; r <= n; r++) {
        rowSum = rowSum * 2 % P;
        ans += rowSum; ans %= P;
    }

    // For the next m - n rows, we just subtract the last element
    for (int r = n + 1; r <= m; r++) {
        rowSum = (2 * rowSum + P - lastEle) % P;
        ans += rowSum; ans %= P;
        lastEle = lastEle * modDiv(r, r - n) % P;
    }

    // For the last n rows we subtract both first and last element
    for (int r = m + 1; r <= m + n; r++) {
        rowSum = (2 * rowSum + 2 * P - lastEle - firstEle) % P;
        ans += rowSum; ans %= P;
        lastEle = lastEle * modDiv(r, r - n) % P;
        firstEle = firstEle * modDiv(r, r - m) % P;
    }

    // Sanity check
    assert(firstEle == lastEle);

    std::cout << ans;

    return 0;
}
