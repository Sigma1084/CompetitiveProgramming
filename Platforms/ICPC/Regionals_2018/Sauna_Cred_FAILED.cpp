#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }


using Range = array<int, 2>;

struct EndsFirstComp {
	bool operator() (Range r1, Range r2) {
		return r1[1] > r2[1];
	}
};


void solve() {
	int n, k; cin >> n >> k; k--;
	vector<Range> R(n);
	for (auto &r: R) cin >> r[0] >> r[1];

	sort(all(R));

	/**
	 * We need 3 queues inside, outside and overlap from where
	 * we will be popping based on whichever ends first
	 */
	priority_queue<Range, vector<Range>, EndsFirstComp> inside, outside, overlap;


	/**
	 * i is the interval number we are currently processing
	 * j is the interval we will process next
	 */
	int i = 0, j = 0;

	int ans = 0;

	while (i < n) {
		while (j < n and R[j][1] < )
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
