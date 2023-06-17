#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

vector<int> primes;

int normalize(ll val, int P) {
	return (P + (val % P)) % P;
}


void solve() {
	int n; cin >> n;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	/**
	 * For any prime p | a_j - a_i
	 *  that implies p does not divide a_i + x
	 *  and naturally p does not divide a_j + x
	 * 
	 * Enough to check for primes less than 100
	 */

	sort(all(a));
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			cout << "NO";
			return;
		}
	}

	for (int &p: primes) {
		vector<bool> poss(p, true);

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (abs(a[j] - a[i]) % p == 0) {
					poss[normalize(a[i], p)] = false;
					poss[normalize(a[j], p)] = false;
				}
			}
		}

		if (accumulate(all(poss), 0) == 0) {
			cout << "NO";
			return;
		}
	}

	cout << "YES";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	bool ok;
	for (int i = 2; i <= 105; i++) {
		ok = true;
		for (int j = 2; j < i; j++) {
			if (gcd(i, j) != 1) {
				ok = false;
				break;
			}
		}
		if (ok) primes.push_back(i);
	}

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
