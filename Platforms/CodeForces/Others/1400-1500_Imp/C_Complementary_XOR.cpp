#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;

	int l = 0, r = n-1;
	char whatIsB = 0;

	vector<array<int, 2>> ans;
	while (l <= r) {
		int numOnes = a[l] + b[l] + b[r] + a[r] - 4 * ('0');
		if (numOnes & 1) {
			cout << "NO";
			return;
		}
		array<int, 4> rowMajor = {a[l] - '0', a[r] - '0', b[l] - '0', b[r] - '0'};
		if (rowMajor == array<int, 4>{0, 1, 1, 0}) {
			/**
			 * 000**100
			 * 111**011
			 * (r, r)
			 */
		} else if (rowMajor == array<int, 4>{1, 0, 0, 1}) {

		}
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
