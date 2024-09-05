#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<array<int, 3>> a(n);
	for (auto &[x, y, _]: a) cin >> x >> y;
	for (int i = 0; i < n; i++) a[i][2] = i;

	int ans = INT_MAX;
	using pii = pair<int, int>;

	multiset<pii, greater<pii>> _fset, _sset;
	for (const auto &[x, y, i]: a) {
		_fset.insert({x, i});
		_sset.insert({y, i});
	}

	multiset<int, greater<int>> f, s;
	multiset<pii, greater<pii>> fCur, sCur;

	// Check when the greatest element of f HAS to be the greatest
	fCur = _fset; sCur = _sset;

	auto updateAns = [&]() -> void {
		pii fMax = {0, -1}, sMax {0, -1};
        if (not fCur.empty()) fMax = *fCur.begin();
        if (not f.empty()) fMax = max(fMax, {*f.begin(), -1});
		if (not sCur.empty()) sMax = *sCur.begin();
		if (not s.empty()) sMax = max(sMax, {*s.begin(), -2});
        if (fMax.second != sMax.second) {
            ans = min(ans, abs(fMax.first - sMax.first));
            return;
        }
        if (fCur.size() > 1) {
            auto it = fCur.begin(); it++;
            ans = min(ans, abs(it->first - sMax.first));
        }
        if (sCur.size() > 1) {
            auto it = sCur.begin(); it++;
            ans = min(ans, abs(fMax.first - it->first));
        }
        if (f.empty()) {
            ans = min(ans, abs(*f.begin() - sMax.first));
        }
        if (s.empty()) {
            ans = min(ans, abs(fMax.first - *s.begin()));
        }
	};


	while (not fCur.empty() and not sCur.empty()) {
		auto [x, i] = *fCur.begin();
		fCur.erase(fCur.begin());
		sCur.erase({a[i][1], i});
		f.insert(x);
		updateAns();
		while (not sCur.empty() and sCur.begin()->first > *f.begin()) {
			auto [y, j] = *sCur.begin();
			sCur.erase(sCur.begin());
			fCur.erase({a[j][0], j});
			f.insert(a[j][0]);
			updateAns();
		}
		f.erase(f.find(x));
		s.insert(a[i][1]);
		updateAns();
	}

	// Check when the the greatest element of s HAS to be the greatest
	s.clear(); f.clear();
	fCur = _sset; sCur = _fset;

	while (not fCur.empty() and not sCur.empty()) {
		auto [x, i] = *fCur.begin();
		fCur.erase(fCur.begin());
		sCur.erase({a[i][0], i});
		f.insert(x);
		updateAns();
		while (not sCur.empty() and sCur.begin()->first > *f.begin()) {
			auto [y, j] = *sCur.begin();
			sCur.erase(sCur.begin());
			fCur.erase({a[j][1], j});
			f.insert(a[j][1]);
			updateAns();
		}
		f.erase(f.find(x));
		s.insert(a[i][0]);
		updateAns();
	}

	cout << ans;
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
