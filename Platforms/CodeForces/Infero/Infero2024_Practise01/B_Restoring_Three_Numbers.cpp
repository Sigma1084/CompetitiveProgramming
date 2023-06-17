#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<int> a(4);
	for (int &i: a) cin >> i;

	sort(a.begin(), a.end());
	for (int i = 0; i < 3; i++) {
		cout << a.back() - a[i] << " \n"[i == 2];
	}

	return 0;
}
