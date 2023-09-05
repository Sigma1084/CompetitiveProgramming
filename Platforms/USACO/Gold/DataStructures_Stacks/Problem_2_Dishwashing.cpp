#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);

	int n; cin >> n;
	vector<int> a(n); for (int &x: a) cin >> x;

	deque<stack<int>> stacks;
	deque<int> bases;  // Ascending
	int i, maxValSent = 0;  // Maximum sent

	for (i = 0; i < n; i++) {
		if (a[i] <= maxValSent) break;
		int ind = lower_bound(bases.begin(), bases.end(), a[i]) - bases.begin();
		if (ind == bases.size()) {
			stacks.push_back(stack<int>());
			bases.push_back(a[i]);
			stacks.back().push(a[i]);
		} else if (stacks[ind].top() > a[i]) {
			stacks[ind].push(a[i]);
		} else {
			if (ind) maxValSent = max(maxValSent, bases[ind - 1]);
			for (int j = 0; j < ind; j++) {
				stacks.pop_front();
				bases.pop_front();
			}
			for (; stacks.front().top() < a[i]; stacks.front().pop()) {
				maxValSent = max(maxValSent, stacks.front().top());
			}
			stacks.front().push(a[i]);
		}
	}

	cout << i << '\n';

	return 0;
}
