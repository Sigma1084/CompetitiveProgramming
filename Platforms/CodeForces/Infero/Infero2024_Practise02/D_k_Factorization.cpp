#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> factors;

	for (int i = 2; i * i <= n and factors.size() < k; i++) {
		if (n % i) continue;
		for (; n % i == 0 and factors.size() < k; n /= i) {
			factors.push_back(i);
		}
	}

	if (factors.size() == k) {
		factors.back() *= n;
	} else {
		if (n > 1) {
			factors.push_back(n);  // n has to be a prime
		}
		if (factors.size() < k) {
			cout << -1;
			return 0;
		}
	}

	for (int f: factors) {
		cout << f << ' ';
	}
	cout << endl;

	return 0;
}
