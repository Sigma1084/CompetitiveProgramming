#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	// We need the common ones that P1 and P2 want
	// We also need the number of tiles that ONLY P1 benifits
	// Similarly the number of tiles that ONLY P2 benifits

	int p1 = 0, p2 = 0, b = 0;
	bool p1w, p2w;
	for (int i = 0; i < n; i++) {
		p1w = false; p2w = false;
		if (a[i] != i+1) p1w = true;
		if (a[i] != n-i) p2w = true;
		if (p1w and p2w) b++;
		else if (p1w) p1++;
		else if (p2w) p2++;
	}

	// Initially let's assume they just do one by one until one of them is 0
	while (p1 and p2) { p1--; p2--; }

	if (p1 == 0 and b <= p2) {
		cout << "First";
	} else if (p2 == 0 and b < p1) {
		cout << "Second";
	} else {
		cout << "Tie";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

