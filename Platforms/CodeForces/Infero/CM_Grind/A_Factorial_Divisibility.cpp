#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n); for (int &i: a) cin >> i;
	sort(all(a));

	vector<int> f(x+1);
	for (int &i: a)
		if (i < x) f[i]++;

	for (int i = 1; i < x; i++) {
		f[i+1] += f[i] / (i+1);
		if (f[i] %= (i+1)) {
			cout << "No";
			return;
		}
	}

	cout << "Yes";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

