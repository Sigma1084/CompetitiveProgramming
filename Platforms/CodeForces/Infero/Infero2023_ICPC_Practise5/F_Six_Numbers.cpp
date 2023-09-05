#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr std::array<int, 6> nums = {4, 8, 15, 16, 23, 42};
map<int, pair<int, int>> m;

int ask(int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	int x; cin >> x;
	return x;
}

void submit(const array<int, 6> &a) {
	cout << "!";
	for (int x: a) cout << ' ' << x;
	cout << endl;
}

int intersect(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first or a.first == b.second)
		return a.first;
	return a.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			int prod = nums[i] * nums[j];
			m[prod] = {nums[i], nums[j]};
		}
	}

	array<int, 6> ans;

	int p1 = ask(1, 2);
	int p2 = ask(2, 3);
	ans[1] = intersect(m[p1], m[p2]);
	ans[0] = p1 / ans[1];
	ans[2] = p2 / ans[1];

	p1 = ask(4, 5);
	p2 = ask(5, 6);
	ans[4] = intersect(m[p1], m[p2]);
	ans[3] = p1 / ans[4];
	ans[5] = p2 / ans[4];

	submit(ans);

	return 0;
}
