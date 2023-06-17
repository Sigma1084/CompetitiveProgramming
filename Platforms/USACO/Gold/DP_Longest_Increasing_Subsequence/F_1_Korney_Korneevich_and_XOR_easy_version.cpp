#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


/**
 * The following solution takes O(n * A) time
 * where A is the maximum value of an element in the array
 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	/**
	 * xs possible ending with i
	 * Always maintain with the least i
	 * 
	 * eg: xs[4] contains 5 implies we can obtain 
	 *   5 from an increasing subsequence ending with 4
	 *   and the least such ending is 4
	 * 
	 * leastEnd[5] = 4
	 */

	constexpr int A_MAX = 512;  // Maximum value of an element in the array
	vector<set<int>> xs(A_MAX);
	vector<int> leastEnd(A_MAX, -1);

	// 0 is possible with empty subsequence and is treated separately
	leastEnd[0] = 0;
	xs[0].insert(0);  

	for (int x: a) {
		if (leastEnd[x] == -1 or leastEnd[x] > x) {
			leastEnd[x] = x;
			xs[x].insert(x);
		}
		for (int i = 0; i < x; i++) {
			for (int j: xs[i]) {
				int k = j ^ x;
				if (leastEnd[k] == -1) {
					leastEnd[k] = x;
					xs[x].insert(k);
				} else if (x < leastEnd[k]) {
					xs[leastEnd[k]].erase(k);
					leastEnd[k] = x;
					xs[x].insert(k);
				}
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < A_MAX; i++) {
		if (leastEnd[i] != -1) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';
	for (int x: ans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
