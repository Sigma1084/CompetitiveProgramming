#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

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
	for (int i=2; i*i < N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i*i; j < N; j += i)
			isPrime[j] = false;
	}

	for (int i=2; i < N; i++) {
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

int highestOneBit(int i) {
	i |= (i >>  1);
	i |= (i >>  2);
	i |= (i >>  4);
	i |= (i >>  8);
	i |= (i >> 16);
	return i ^ (i >> 1);
}

/* Iterate through all the submasks of m */
void iterateSubMasks(int m) {
	for (int s = m; s; s = (s-1)&m)
		cout << s << '\n';
}

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

template <class T>
T _pow(T a, long long int b) { T ans = 1; for (; b; b /= 2, a *= a) if (b % 2) ans *= a; return ans; }

template <unsigned int P>
struct MI {
	using ll = long long int;
	ll value = 0;
	MI() = default;
	MI(const ll &v): value((P + v%P) % P) {}
	MI(const int &v): MI<P>((ll) v) {}
	void normalize() { if (value < 0) value += P; if (value > P) value -= P; }
	MI<P> operator - () const { return MI<P>(-value); }
	MI<P> operator ++ (int) { return operator+=(1); }
	MI<P> operator -- (int) { return operator-=(1); }
	unsigned int operator ()() const { return value; }
	MI<P>& operator += (const MI<P> &a) { value += a.value; normalize(); return *this; }
	MI<P>& operator -= (const MI<P> &a) { value -= a.value; normalize(); return *this; }
	MI<P>& operator *= (const MI<P> &a) { (value *= a.value) %= P; return *this; }
	MI<P> inv() const { return _pow(*this, P-2); }
	MI<P>& operator /= (const MI<P> &a) { (value *= a.inv().value) %= P; return *this; }
	bool operator == (const MI<P> &a) { return value == a.value; }
	bool operator != (const MI<P> &a) { return value != a.value; }
	friend MI<P> operator + (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans += b; }
	friend MI<P> operator - (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans -= b; }
	friend MI<P> operator * (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans *= b; }
	friend MI<P> operator / (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans /= b; }
	friend std::ostream& operator << (std::ostream &o, const MI<P> &m) { return o << m.value; }
	friend std::istream& operator >> (std::istream &i, MI<P> &m) { return i >> m.value; }
};

const int P = 1e9 + 7;

typedef MI<P> Z;


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

void seg_sum(ll &a, const ll &b) { a += b; }  // init = 0
void seg_min(int &a, const int &b) { a = min(a, b); }  // init = INT_MAX
void seg_max(int &a, const int &b) { a = max(a, b); }  // init = INT_MIN
void seg_gcd(int &a, const int &b) { a = __gcd(a, b); }  // init = 0

/**
 * @brief Segment Tree Class
 * 
 * Rooted at 1
 * Left Child is 2*n and Right Child is 2*n + 1
 */
template<typename T>
struct SegmentTree {
	typedef function<void(T&, const T&)> Operation_t;
	const T init;
	const Operation_t operation;

	vector<T> tree;
	int n;

	/**
	 * @brief Construct a new Segment Tree object
	 * @param _n Number of elements
	 * @param init Initial xue
	 * @param operation Operation
	 */
	SegmentTree(const int &_n, const T &init, const Operation_t &operation):
		n(_n), init(init), operation(operation) {
		n = pow(2, ceil(log2(n)));
		tree.resize(2 * n, init);
	}
	
	/**
	 * @brief Construct a new Segment Tree object using an array
	 * @param a Array
	 * @param init Initial xue
	 * @param operation Operation
	 */
	SegmentTree(const vector<T> &a, const T &init, const Operation_t 
		&operation): n(a.size()), init(init), operation(operation) {
		n = pow(2, ceil(log2(n)));
		tree.resize(2 * n, init);
		for (int i = 0; i < a.size(); i++)
			tree[n+i] = a[i];
		for (int i = n-1; i > 0; i--)
			tree[i] = tree[2*i], operation(tree[i], tree[2*i + 1]);
	}
	
	/**
	 * @brief Operation(a[i], v) (i is ZERO INDEXED)
	 * @param i Index
	 * @param v xue
	 */
	void update(int i, const T &v) {
		for (int temp = n + i; temp; temp /= 2)
			operation(tree[temp], v);
	}
	
	/**
	 * @brief Operations of elements in [l, r] 0 indexed
	 * @param l Left index
	 * @param r Right index
	 * @return Operations of elements in [l, r]
	 */
	int query(int l, int r) {
		T res = init;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2 == 1) operation(res, tree[l++]);
			if (r % 2 == 0) operation(res, tree[r--]);
		}
		return res;
	}
};
