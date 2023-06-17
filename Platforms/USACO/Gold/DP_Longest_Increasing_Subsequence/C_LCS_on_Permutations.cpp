#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int &x: a) { cin >> x; x--; }
	for (int &x: b) { cin >> x; x--; }

	/**
	 * Following https://usaco.guide/problems/cf-lis-on-permutations/solution
	 * 
	 * pos[x] := Position of x in a
	 * Now, construct c = pos(b), that is c[i] = pos[b[i]]
	 * The answer is the length of the LIS of c
	 */
	vector<int> pos(n), c(n);
	for (int i = 0; i < n; i++) pos[a[i]] = i;
	for (int i = 0; i < n; i++) c[i] = pos[b[i]];

	// LIS of c
	vector<int> lis; lis.push_back(c[0]);
	for (int x: c) {
		if (x > lis.back()) lis.push_back(x);
		else *lower_bound(lis.begin(), lis.end(), x) = x;
	}

	cout << lis.size();

	return 0;
}
