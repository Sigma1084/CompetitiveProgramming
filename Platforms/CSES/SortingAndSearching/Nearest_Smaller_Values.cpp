#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	cout << 0;
	stack<int> s; s.push(a[0]);

	return 0;
}
