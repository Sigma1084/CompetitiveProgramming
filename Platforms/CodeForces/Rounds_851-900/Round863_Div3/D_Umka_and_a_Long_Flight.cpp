#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

constexpr int MAX_N = 45;
array<ll, MAX_N + 1> fib;


void solve() {
	int n; cin >> n;
	ll x, y; cin >> x >> y;

	/**
	 * F(n+1) - F(n) = F(n-1)
	 * 
	 * Hence, if we delete a rectangle of size F(n)*F(n)
	 * from some side, we will get a rectangle of size
	 * [F(n+1) - F(n)] x F(n) = F(n-1) * F(n)
	 * which is a Fibonacci Rectangle of order n-1
	 * 
	 * Hence, we can solve the problem using recursion
	 */

	for (; n >= 1; n--) {
		// Moving it above so deleting is easier
		y = min(y, 1 + fib[n+1] - y);
		if (y > fib[n-1]) {
			cout << "NO";
			return;
		}
		swap(x, y);
	}

	cout << "YES";
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	fib[0] = 1; fib[1] = 1;
	for (int i = 2; i <= MAX_N; i++)
		fib[i] = fib[i-1] + fib[i-2];

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
