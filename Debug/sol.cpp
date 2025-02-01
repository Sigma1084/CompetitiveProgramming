#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unsigned int countInv(array<int, 2> a, array<int, 2> b) {
	return (a[0] > a[1]) + (a[0] > b[0]) + (a[0] > b[1])
		+ (a[1] > b[0]) + (a[1] > b[1]) + (b[0] > b[1]);
}

bool comp(array<int, 2> a1, array<int, 2> a2) {
	return countInv(a1, a2) < countInv(a2, a1);
}

void solve() {
	int n;
	cin >> n;

	vector<array<int, 2>> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}

	sort(a.begin(), a.end(), comp);
	for (const auto &[x, y] : a) {
		cout << x << ' ' << y << ' ';
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output_sol.txt", "w", stdout);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
