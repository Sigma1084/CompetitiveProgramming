#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

bool comp(const vector<int> &a, int b) {
	return a.back() < b;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<vector<int>> lis;
	ll ans = 0;
	for (int i: a) {
		vector<vector<int>>::iterator vIt;
		if (lis.empty() or lis.back().back() < i) {
			lis.push_back({i});
			vIt = lis.end()--;
		} else {
			vIt = lower_bound(all(lis), i, comp);
			vIt->push_back(i);
		}
		if (vIt != lis.begin()) {
			ans += 
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
