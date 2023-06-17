#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    if (&ost == &cerr) { cerr << "["; for(const auto &x: v) cerr << ' ' << x; cerr << " ]"; }
    else for (const auto &x: v) ost << x << ' '; return ost;
}

void solve() {
	ll n; cin >> n;

	/**
	 * For a given n, suppose the answer is f(n).
	 * Notice that when we have f(2^k + 2^l) = f(2^k) + f(2^l) when k != l.
	 * 
	 * Also, f(2^k) = 2 * f(2^(k-1)) + 1  =>  f(2^k) = 2^(k+1) - 1
	 * 
	 *  000 : f(0) =  0
	 *  001 : f(1) =  1
	 *  010 : f(2) =  3 = 2 * f(1) + 1
	 *  011 : f(3) =  4 = f(2) + f(1)
	 *  100 : f(4) =  7 = 2 * f(2) + 1
	 *  101 : f(5) =  8 = f(4) + f(1)
	 *  110 : f(6) = 10 = f(4) + f(2)
	 *  111 : f(7) = 11 = f(4) + f(2) + f(1)
	 * 1000 : f(8) = 15 = 2 * f(4) + 1
	 * 
	 * f(2^k) = 2^(k+1) - 1
	 */

	ll ans = 0;
	for (int i = 0; i < 60; i++) {
		if ((1LL << i) & n) {
			ans += (1LL << (i + 1)) - 1;
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
