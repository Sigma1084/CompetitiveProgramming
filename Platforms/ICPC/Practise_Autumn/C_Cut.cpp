#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int N = 1e5;

bool isPrime[N + 1];
std::vector<int> primes;
int lPF[N + 1];  // Least Prime Factor

void updatePrimes() {
	for (int i = 0; i <= N; i++) {
		lPF[i] = i;
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			isPrime[j] = false;
			if (lPF[j] == j) lPF[j] = i;
		}
	}
	for (int i = 2; i <= N; i++)
		if (isPrime[i]) primes.push_back(i);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	updatePrimes();

	int n, q; cin >> n >> q;
	const int K = log2(n);

	vector<int> a(n);
	for (int &i: a) cin >> i;

	// st[k][i] := ans for [i, i + 2^k)
	vector<vector<array<int, 2>>> st(K + 1);
	for (int k = 0; k <= K; k++) {
		st[k].resize(n - (1 << k) + 1, {-1, 0});
	}

	// Setting base cases
	set<int> primes;
	vector<int> p;  // factorization
	int prevJ = -1;

	auto updateP = [&] (int j) {
		if (j == prevJ) return;
		prevJ = j;

		p.clear();
		for (int x = a[j]; x > 1; x /= lPF[x]) {
			p.push_back(lPF[x]);
		}
	};

	auto conf = [&] () {
		for (int x: p) {
			if (primes.count(x)) {
				return true;
			}
		}
		return false;
	};

	for (int i = 0, j = 0; i < n; i++) {
		while (j < n) {
			updateP(j);
			if (conf()) {
				st[0][i] = { 1, j };
				break;
			} else {
				// No conflict
				for (int x: p) {
					primes.insert(x);
				}
				j++;
			}
		}

		if (j == n) {
			st[0][i] = { 1, n };
			continue;
		}

		// Remove a[i]
		updateP(i);
		for (int x: p) {
			primes.erase(x);
		}
	}

	function<array<int, 2>(int, int)> query = [&](int l, int r) {
		int x = r + 1 - l;
		if ((x & (x - 1)) == 0 and st[int(log2(x))][l][0] != -1) {
			return st[int(log2(x))][l];
		}

		array<int, 2> *ans = nullptr;
		if ((x & (x - 1)) == 0) {
			ans = &st[int(log2(x))][l];
		}

		int d = log2(--x);
		auto ans1 = query(l, l + (1 << d) - 1);
		if (ans1[1] <= r) {
			auto ans2 = query(ans1[1], r);
			ans1 = array<int, 2>{ ans1[0] + ans2[0], ans2[1] };
		}

		if (ans != nullptr) {
			*ans = ans1;
		}

		return ans1;
	};

	for (int _ = 0, l, r; _ < q; _++) {
		cin >> l >> r; l--; r--;
		cout << query(l, r)[0] << '\n';
	}

	return 0;
}
