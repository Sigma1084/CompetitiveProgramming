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
 *   <li> 1 << n  --> Stretch 1 to the left n times => 2^n </li>
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

typedef long long int ll;
const int MOD = 1e9 + 7;

template <unsigned int MOD=MOD>
struct ModInt {
    long long int val = 0;
    ModInt() = default;
    ModInt(int v): val((MOD + v) % MOD) {}
    void operator += (const int &a)
    { val += 0ll + MOD + a; val %= MOD; }
    void operator *= (const int &a)
    { val *= a; val %= MOD; if (val < 0) val += MOD; }
};
typedef ModInt<> Mod;

// a ^ b (mod MOD)
ll modPow(ll a, ll b) {
  if (b == 0) return 1;
  ll x = modPow(a, b/2) % MOD;
  x = (x * x) % MOD;
  return (x * (b%2 ? a : 1)) % MOD;
}

// Using Fermat's Little Theorem, (only works for prime MOD)
ll modInverse(ll a) {
  return modPow(a, MOD-2);
}

struct DSU {
    vector<int> p;
    DSU (const int &MAX) {
        p = vector<int>(MAX+1);
        for (int i=1; i<=MAX; i++) p[i] = i;
    }
    int find (const int &i) {
        if (p[i] == i) return i;
        return p[i] = find(p[i]);
    }
    void set_union(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return;
        if (i > j) p[i] = j;
        else p[j] = i;
    }
};

void seg_sum(ll &a, const ll &b) { a = a + b; }
void seg_min(int &a, const int &b) { a = min(a, b); }
void seg_max(int &a, const int &b) { a = max(a, b); }

template<typename T>
struct SegmentTree {
    typedef function<void(T&, const T&)> Operation_t;
    vector<T> tree;
    int n;
    const T init;
    const Operation_t operation;
    SegmentTree(int n, T init, Operation_t operation): 
        n(n), init(init), operation(operation) {
        /**
         * @brief Default Constructor
         * @param n: Number of elements of the array
         */
        n = pow(2, ceil(log2(n)));
        tree.resize(2 * n, init);
    }
    void update(int i, const T &v) {
        /**
         * @brief a[i] += v (i is ZERO INDEXED)
         * @param i Index
         * @param v Value
         */
        for (int temp = this->n + i; temp >= 1; temp /= 2) 
            operation(tree[temp], v);
    }
    int query(int l, int r) {
        /**
         * @brief Sum of elements in [l, r]
         * @param l Left index
         * @param r Right index
         * @return Sum of elements in [l, r]
         */
        T res = init;
        l += n, r += n;
        while (l <= r) {
            if (l % 2 == 1) operation(res, tree[l++]);
            if (r % 2 == 0) operation(res, tree[r--]);
            l /= 2, r /= 2;
        }
        return res;
    }
};
