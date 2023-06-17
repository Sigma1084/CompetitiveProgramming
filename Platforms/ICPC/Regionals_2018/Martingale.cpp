#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

void solve() {
	int n; cin >> n;
	double ans = 0;
	for(int i = 2*n - 1, k; i >= n; i--) {
		k = ceil(log2(i+1));
		ans = (1 - 1.0 / (1 << k)) * (2.0 + ans);
	}
	cout << fixed << setprecision(7) << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
