#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(n); for (int &i: a) cin >> i;

	map<int, int> f;
	int ansL = -1, ansR = -1, ans = 0;
	// int l = 0, r = 0; f[a.front()]++;

	f[a.front()]++;
	for (int l = 0, r = 0; r < n; ) {
		if (f.size() > k) {  // Bad, start cutting
			f[a[l]]--;
			if (f[a[l]] == 0) f.erase(a[l]);
			l++;
		} else {
			if (r - l + 1 > ans) {
				ans = r - l + 1;
				ansR = r; ansL = l;
			}
			r++;
			if (r < n) f[a[r]]++;
		}
		// cerr << l << ' ' << r << ".. ";
		// for (auto [x, fr]: f) cerr << x << ": " << fr << ", ";
		// cerr << '\n';
	}

	cout << ansL + 1 << ' ' << ansR + 1 << '\n';

	return 0;
}
