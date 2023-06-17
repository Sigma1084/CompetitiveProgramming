#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	set<int> pos, neg;
	for (int &i: a) if (i > 0) pos.insert(i);
	for (int &i: a) if (i < 0) neg.insert(i);

	// Maximum
	for (int i = 1; i <= pos.size(); i++) cout << i << ' ';
	for (int i = pos.size() - 1, j = 0; j < n - pos.size(); j++, i--)
		cout << i << ' ';
	cout << '\n';

	// Minimum
	for (int i = 0; i < neg.size(); i++)
		cout << "1 0 ";
	
	for (int i = 1; i <= n - 2*neg.size(); i++)
		cout << i << ' ';
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
