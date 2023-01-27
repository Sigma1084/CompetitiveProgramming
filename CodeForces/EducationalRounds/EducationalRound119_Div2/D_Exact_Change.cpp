#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	sort(all(a));

	if (a.back() % 3 == 1) {
		// a.back() % 3 == 1 OR 3k + 1
		// 7 9 10
		// We can have 3 3 2 2 or 3 3 3 1 or 3 3 3 1 1
		
		// If we have a 1, we NEED a 1 and hence
		bool is1Pres = false, is3K = false, is3k2 = false;
		for (int &i: a) if (i == 1) is1Pres = true;
		for (int &i: a) if (i == a.back() - 1) is3K = true;
		for (int &i: a) if (i % 3 == 2) is3k2 = true;

		if (is1Pres) {
			if (is3k2) {
				cout << a.back() / 3 + 2;
			} else {
				cout << a.back() / 3 + 1;
			}
		} else {
			if (is3K) {
				cout << a.back() / 3 + 1 + is3k2;
			} else {
				cout << a.back() / 3 + 1;
			}
		}
	} else if (a.back() % 3 == 0) {
		// Do we need either 1 and 2 is the question
		// If we do, then answer is just k + 1 since k-1 3s and 1 2
		// Suppose k = 3, back = 9, we have the choices 3 3 3 or 3 3 1 2
		bool ok = false;
		for (int &i: a) if (i % 3) ok = true;
		cout << a.back() / 3 + ok;
	} else {
		// a.back() % 3 == 2 OR 3k + 2
		// Suppose k = 3, back = 11
		// Possible combs = 3 3 3 2, 3 3 3 1 1
		bool is3k1 = false;
		for (int &i: a) if (i % 3 == 1) is3k1 = true;
		cout << a.back() / 3 + 1 + is3k1;
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
