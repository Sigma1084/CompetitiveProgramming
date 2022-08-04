#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

string strSlice(string s, int start, int end) {
    int l = s.length();
    string ans = "";
    if (end == -1) end = s.length();
    if (start < 0 || start >= l) return ans;
    if (end <= start || end > l) return ans;
    for (int i=start; i<end; i++) ans += s[i];
    return ans;
}

// Greatest Triangular Number Less than or equal to
int greatestTriLE(int s) {
    int k = ceil(sqrt(2 * s));
    while (k*(k+1) > 2*s) k--;
    return k;
}

// Number Theory
template <class T>
T phi(T n) {
    if (n == 1) return 0;
    T ans = 1;
    for (T curr = 2; curr*curr <= n and n > 1; curr++) {
        if (n%curr != 0) continue;
        // n divides curr
        T mult = 1;
        while (n%curr == 0) mult *= curr, n /= curr;
        ans *= (mult - mult/curr);
    }
    // If n > 1 then it is some prime p
    if (n > 1) ans *= (n-1);
    return ans;
}

const int N = 1e5 + 3;
vector<bool> isPrime(N, true);
vector<int> primes;

void updatePrimes() {
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= N; j += i)
            isPrime[j] = false;
    }

    for (int i=2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}


/** <h2> Bitwise Functions </h2> <ul>
 *   <li> n >> d  --> Right shift d times (Divide by 2^d) </li>
 *   <li> n & 1  --> Last digit </li>
 *   <li> (n>>d) << d  --> Make the last d digits zeros </li>
 *   <li> n % ((n>>d) << d)  --> Get the last d digits </li>
 * </ul>
 */


/** <h2> Set </h2> <ul>
 *   <li>  </li>
 *   <li>  </li>
 *   <li>  </li>
 *   <li>  </li>
 * </ul>
 */

/*****************************************************************/

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

int maxFreq(int a[], int n) {
    vi freqs = getFreqs(a, n);
    sort(freqs.begin(), freqs.end());
    return freqs[freqs.size()-1];
}
