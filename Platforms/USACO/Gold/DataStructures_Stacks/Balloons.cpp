#include <bits/stdc++.h>
using namespace std;

double maxRadius(int x1, int x2, double r1) {
	return 1LL * (x2 - x1) * (x2 - x1) / (4 * r1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	stack<pair<int, double>> st;  // [position, radius]
	cout << fixed << setprecision(3);

	for (int i = 0; i < n; i++) {
		int x2; cin >> x2;
		double r2; cin >> r2;
		while (not st.empty()) {
			auto [x1, r1] = st.top();
			r2 = min(r2, maxRadius(x1, x2, r1));
			if (r2 < r1) break;
			st.pop();
		}
		st.emplace(x2, r2);
		cout << r2 << '\n';
	}

	return 0;
}
