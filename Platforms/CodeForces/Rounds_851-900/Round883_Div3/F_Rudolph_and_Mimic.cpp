#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

map<int, int> getFreq(const vector<int> &a) {
	map<int, int> freq;
	for (int i: a) freq[i]++;
	return freq;
}

void remVec(const vector<int> &a) {
	cout << "- " << a.size();
	for (int i: a) cout << ' ' << i + 1;
	cout << endl;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n), rem;
	map<int, int> f1, f2, f3;
	
	for (auto &x: a) cin >> x;
	f1 = getFreq(a);
	f2 = f1;

	while (f1 == f2) {
		remVec(rem);
		for (auto &x: a) cin >> x;
		f2 = getFreq(a);
	}

	// Now, remove all those except the new color
	for (int i = 0; i < n; i++) {
		if (f1[a[i]] >= f2[a[i]])
			rem.push_back(i);
		else
			f3[a[i]]++;
	}

	remVec(rem);
	n -= rem.size();
	rem.clear();
	a.resize(n);
	f1 = f3;

	for (auto &x: a) cin >> x;
	f2 = getFreq(a);

	while (f1 == f2) {
		remVec(rem);
		for (auto &x: a) cin >> x;
		f2 = getFreq(a);
	}

	// Now, remove all those except the new color
	for (int i = 0; i < n; i++) {
		if (f1[a[i]] >= f2[a[i]])
			rem.push_back(i);
		else {
			cout << "! " << i + 1 << endl;
			return;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();
	}

	return 0;
}
