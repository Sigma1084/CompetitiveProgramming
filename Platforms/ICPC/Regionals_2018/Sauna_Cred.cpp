#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pii = pair<int, int>;
using oset = tree < pii ,  null_type ,  less<pii> ,  rb_tree_tag ,  tree_order_statistics_node_update >;


template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }


using Range = array<int, 3>;


void solve() {
	int n, k; cin >> n >> k; k--;
	vector<Range> R(n); for (auto &x: R) cin >> x[0] >> x[1];

	oset rA, rB;
	for (int i = 0; i < n; i++) {
		rA.insert({ R[i][1], i });
	}

	int ans = 0;  // Start and end before 0
	for (int i = 0, l, r, out, in; i < n; i++) {
		// Here, the ones after this is given by 
		l = R[i][0]; r = l + k;

		// The number of intervals outside it is given by
		//   the number of elements in rB which are strictly greater than r
		//   since they are the only elements that start before l
		out = rB.size() - rB.order_of_key({r+1, 0});

		// The number of intervals inside is given by
		//   the number of elements in rA which are less than or equal to r
		//   since they are the only elements which start after l
		in = rA.order_of_key({r, n});

		rB.insert({ R[i][1], i });
		rA.erase({ R[i][1], i });

		ans = max(ans, in - out);
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
