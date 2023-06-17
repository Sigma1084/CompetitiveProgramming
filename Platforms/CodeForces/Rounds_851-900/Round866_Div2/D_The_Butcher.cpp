#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;

void solve() {
	int n; cin >> n;
	multiset<pii> _wh, _hw;
	ll area = 0;

	for (int i = 0, w, h; i < n; i++) {
		cin >> h >> w;
		area += 1LL * h * w;
		_wh.emplace(w, h);
		_hw.emplace(h, w);
	}

	function<bool(int, int)> isPossible = [&] (int H, int W) -> int {
		auto hw = _hw, wh = _wh;

		while (not hw.empty()) {
			auto [w, h] = *wh.rbegin();
			if (w == W) {
				if (h > H) return false;
				H -= h;
				wh.erase(wh.find({w, h}));
				hw.erase(hw.find({h, w}));
				continue;
			}

			h = hw.rbegin()->first; w = hw.rbegin()->second;
			if (h == H) {
				if (w > W) return false;
				W -= w;
				wh.erase(wh.find({w, h}));
				hw.erase(hw.find({h, w}));
				continue;
			}

			return false;
		}

		return true;
	};


	int H, W;
	set<pii> ans;

	H = _hw.rbegin()->first;
	W = area / H;
	if (area == 1LL * H * W and isPossible(H, W)) {
		ans.emplace(H, W);
	}

	W = _wh.rbegin()->first;
	H = area / W;
	if (area == 1LL * H * W and isPossible(H, W)) {
		ans.emplace(H, W);
	}

	cout << ans.size() << '\n';
	for (auto [h, w]: ans) {
		cout << h << ' ' << w << '\n';
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
