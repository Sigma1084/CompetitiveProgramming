#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a;
	a.push_back(MOD);
	for (int i = 0; i < n; i++) {
		int cur; cin >> cur;
		if (a.empty() or a.back() != cur) {
			a.push_back(cur);
		}
	}
	a.push_back(MOD);

	int numVals = 0;
	n = a.size();
	for (int i = 1; i+1 < n; i++) {
		if (a[i-1] > a[i] and a[i] < a[i+1])
			numVals++;
	}

	if (numVals == 1) {
		cout << "YES";
	} else {
		cout << "NO";
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

