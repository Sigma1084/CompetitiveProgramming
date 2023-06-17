#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


const int maxNP = 2;

void solve() {
	int n; cin >> n;
	int pC = 0;

	array<int, maxNP> p; for (int &i: p) i = 0;
	array<int, maxNP> e; for (int &i: e) i = 0;

	int m = n;
	for (int i = 2; i*i <= m and pC < maxNP; i++) {
		if (m % i == 0) {
			p[pC] = i;
			while (m and m % i == 0) {
				e[pC]++;
				m /= i;
			}
			pC++;
		}
	}

	if (pC < maxNP and m > 1) {
		p[pC] = m; m = 1;
		e[pC++] += 1;
	}

	if (pC >= 2) {
		// 1 p n/p
		cout << 1 << ' ' << p[0] << ' ' << n / p[0];
	} else if (pC == 1 and e[0] >= 3) {
		// 1 p n/p => n/p > p^2
		cout << 1 << ' ' << p[0] << ' ' << n / p[0];
	} else {
		cout << -1;
	}
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
