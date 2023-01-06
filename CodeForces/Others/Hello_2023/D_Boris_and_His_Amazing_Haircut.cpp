#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n+2); a[0] = 0; a[n+1] = 0;
	vector<int> b(n+2); b[0] = 0; b[n+1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	int m, x; cin >> m;
	map<int, int> avail;
	for (int _ = 0; _ < m; _++) {
		cin >> x;
		avail[x]++;
	}

	vector<array<int, 2>> fixedBef;
	vector<array<int, 2>> req;  // x, pos
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			cout << "NO";
			return;
		} else if (a[i] == b[i]) {
			fixedBef.push_back({b[i], i});
		} else {
			req.push_back({b[i], i});
		}
	}

	if (req.empty()) {
		cout << "YES";
		return;
	}

	auto comp = [] (auto &x, auto &y) {
		if (x[0] > y[0]) return true;
		if (x[0] < y[0]) return false;
		return x[1] < y[1];
	};

	sort(all(fixedBef), comp);
	sort(all(req), comp);

	set<int> fixed = {0, n+1};
	int fixedBefInd = 0, curX = -1, curXAns = 0, reqL = 0, reqR = -1, endR = -1;

	avail[-1] = 2; req.push_back({0, 0});  // So that we don't need to handle the last element
	for (int j = 0; j < req.size(); j++) {
		if (curX == req[j][0] and req[j][1] < endR) {
			reqR = j;
			continue;
		}

		curXAns += 1;
		for (int k = reqL; k <= reqR; k++)
			fixed.insert(req[k][1]);

		if (curX != req[j][0]) {
			if (avail[curX] < curXAns) {
				cout << "NO";
				return;
			}
			curX = req[j][0];
			curXAns = 0;
			while (fixedBefInd < fixedBef.size() and fixedBef[fixedBefInd][0] > curX) {
				fixed.insert(fixedBef[fixedBefInd++][1]);
			}
		}

		reqL = reqR = j;
		endR = *fixed.upper_bound(req[j][1]);
	}

	cout << "YES";
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
