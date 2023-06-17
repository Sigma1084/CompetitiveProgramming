#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

struct Range {
	enum Type: int8_t { ZERO = 0, ONE = 1, OTHER = 2 };
	Type type;
	int l, r;
	int len() const { return r - l + 1; }
	friend ProcessedRange operator + (const Range &lhs, const Range &rhs) {
		assert(lhs.type == ZERO and rhs.type == ONE);
		ProcessedRange res;
		res.l = lhs.l; res.r = rhs.r;
		res.numZerosBefore = vector<int>(1, lhs.len());
		res.numOnes = rhs.len();
		return res;
	}
};

struct ProcessedRange: Range {
	vector<int> numZerosBefore;
	int numOnes;
	bool check() const { return accumulate(all(numZerosBefore), 0) + numOnes == len(); }
	friend ProcessedRange operator + (const ProcessedRange &lhs, const ProcessedRange &rhs) {
		if (lhs.numOnes < rhs.numOnes) {
			
		}
	}
};


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<ll> nC2(n + 3);
	for (int i = 1; i < n + 3; i++) {
		nC2[i] = 1LL * i * (i + 1) / 2;
	}

	vector<ll> nC3(n + 4);
	for (int i = 1; i < n + 4; i++) {
		nC3[i] = 1LL * i * (i + 1) * (i + 2) / 6;
	}

	vector<Range> ranges;
	ranges.push_back( { Range::Type(s[0] - '0'), 0, 0 } );
	for (int i = 1; i < n; i++) {
		if (ranges.back().type == s[i] - '0') {
			ranges.back().r = i;
		} else {
			ranges.push_back( { Range::Type(s[i] - '0'), i, i } );
		}
	}

	ll ans = 0;
	vector<Range> processed;

	for (const auto &range: ranges) {
		const auto &[type, l, r] = range;
		if (type == Range::ONE) {
			ans += nC2[range.len()];
		} else {

		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
