#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int m, n;
    cin >> m >> n;

    // (1 <= m <= n <= 1000000000, n-m<=100000)

    // Code starts here

    int ans = 0;

    // Special Cases

    // n = 1 or m = 1
    if (n == 1) {
        cout << 0;
        return;
    }

    if (m == 1)
        m = 2;

    // m,n >= 2

    // n = 2 forces m = n = 2
    if (n == 2) {
        cout << 1;
        cout << 2 << "\n";
        return;
    }

    // n > 2

    // This basically contains an even number which is not 2
    if (m == n && m%2 == 0) {
        cout << 0;
        return;
    }

    if (m == 2) {
        ans++;
        cout << 2 << "\n";
        m++;
    }

    // m > 2

    if (m%2 == 0)
        m++;

    // m is odd

    // Code assuming n, m >= 3 and m is odd
    // We are ignoring all the multiples of 2

    int sqrtN = (int) sqrt(n);

    bool isPrime[sqrtN+1];

    /*
     * We basically calculate all the primes less than or equal to sqrt(n)
     * The key idea of the Algorithm:
     *     If any number i, m <= i <= n is composite,
     *     there exists some prime, less than or equal to sqrt(i)
     */

    bool a[n-m+1];  // Use a[x-m] to access if x is a prime

    for (int i=0; i<=sqrtN; i++)
        isPrime[i] = true;

    for (int i=0; i<=n-m; i++)
        a[i] = true;

    /*
     * For any other odd i,
     * All the multiples of i which are less than i*i will already be set to false
     *     (by some other prime factor which is less than i)
     *
     * We set isPrime[multiple_of_i] to be false
     * We set a[multiple_of_i] to be false
     */


    // We increment by 2 since we know evens > 2 can't be prime
    for (int i=3; i<=sqrtN; i+=2) {
        // If we know i is not a prime, we just don't do anything since it's already taken care of by the prime
        if (!isPrime[i])
            continue;

        // First set all isPrime[multiple_of_i] to be false
        // We start from i*i since we know the factors less than i*i are taken care of by a lower prime
        // We increment by 2*i since we are ignoring multiples of 2
        for (int j=i*i; j<=sqrtN; j += 2*i)
            isPrime[j] = false;

        // start is the smallest multiple_of_i (>= i*i) in the range [m, n]
        // We do it since the multiples less than i*i are already taken care of by a smaller prime
        int start = i * (int) ceil((double) m / i);

        if (start < i*i)
            start = i*i;

        // Considering only the odd multiples
        if (start%2 == 0)
            start += i;
        // We increment by 2*i since we are ignoring all the numbers divisible by 2
        for (int j=start; j <= n; j += 2*i)
            a[j-m] = false;
    }

    // After this, we know that in the array a[j-m], all the composites are set to false

    // Ignoring the numbers divisible by 2
    for (int i=m; i<=n; i+=2) {
        if (a[i-m]) {
            ans++;
            cout << i << "\n";
        }
    }

    // cout << ans;
}


int main() {
    int t;
    cin >> t;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}

