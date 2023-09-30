#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using ordered_set = __gnu_pbds::tree<T,
	__gnu_pbds::null_type,
	std::less<T>,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, nQ;
	cin >> n >> m >> nQ;

	vector<int> numOcc(m);  // number of occurances
	// indsWithOcc[0] = list of indices with 0 occurances
	vector<vector<int>> indsWithOcc(n + 1);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		numOcc[x - 1]++;
	}
	for (int i = 0; i < m; ++i) {
		indsWithOcc[numOcc[i]].push_back(i);
	}

	// [k, index]
	vector<array<ll, 2>> queries(nQ);
	vector<ll> ans(nQ);
	int q = 0;
	for (auto &[k, index]: queries) {
		cin >> k;
		index = q++;
		k -= n;
	}
	sort(queries.begin(), queries.end());

	// Real shit
	ordered_set<int> os;
	ll cur = 0;
	q = 0;  // Pointer to keep track of the number of answered queries

	for (int i = 0; i <= n and q < nQ; i++) {
		// Make everything having i + 1 occurances
		for (auto x: indsWithOcc[i]) os.insert(x);
		// We need to go os.size() steps to make
		for (; q < nQ and queries[q][0] - cur <= os.size(); q++) {
			ans[queries[q][1]] = *os.find_by_order(queries[q][0] - cur - 1);
		}
		cur += os.size();
	}

	// We have all the m cities cycling now
	// Now for the remaining
	for (; q < nQ; ++q) {
		auto &[k, index] = queries[q];
		ans[queries[q][1]] = (k - cur - 1) % m;
	}

	for (int x: ans) {
		cout << x + 1 << '\n';
	}
	cout << endl;

	return 0;
}
