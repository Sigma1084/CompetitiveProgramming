#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	stack<pair<int, int>> st;
	st.emplace(0, 0);

	for (int i = 0; i < n; i++) {
		while (st.top().second >= a[i])
			st.pop();
		cout << st.top().first << ' ';
		st.emplace(i + 1, a[i]);
	}

	return 0;
}
