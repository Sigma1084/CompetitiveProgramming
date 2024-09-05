#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;


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
	sort(a, a + n);  // Sort
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

