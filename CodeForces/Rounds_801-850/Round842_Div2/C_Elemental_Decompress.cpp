#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> b(n); for (int &i: b) cin >> i;

	vector<array<int, 2>> a(n);
	for (int i = 0; i < n; i++)
		a[i] = { b[i], i };

	vector<int> p(n, 0), q(n, 0);
	set<int> pS, qS;
	for (int i = 1; i <= n; i++)
		pS.insert(i), qS.insert(i);

	sort(all(a));

	for (int i = n-1; i >= 0; i--) {
		const auto &[ele, ind] = a[i];
		if (pS.count(ele)) {
			p[ind] = ele;
			pS.erase(ele);
		} else if (qS.count(ele)) {
			q[ind] = ele;
			qS.erase(ele);
		} else {
			cout << "NO";
			return;
		}
	}

	for (int i = n-1; i >= 0; i--) {
		const auto &[ele, ind] = a[i];
		if (!p[ind]) {
			p[ind] = *pS.rbegin();
			pS.erase(p[ind]);
		} else {
			q[ind] = *qS.rbegin();
			qS.erase(q[ind]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (max(p[i], q[i]) != b[i]) {
			cout << "NO";
			return;
		}
	}

	cout << "YES\n";
	for (int &i: p) cout << i << ' '; cout << '\n';
	for (int &i: q) cout << i << ' ';
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
