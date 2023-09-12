#include "../range_queries/SparseTable.hpp"
#include <cassert>
#include <iostream>
#include <numeric>

int main() {
	constexpr int n = 5;
	std::vector<int> v(n);
	std::iota(v.begin(), v.end(), 1);
	SparseTable<int> st(v, SparseTable<int>::max);

	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			assert(st.query(l, r) == r + 1);
		}
	}
	std::cout << "Passed query (l, r) for all l, r\n";

	// Ability to change the merger function.
	SparseTable<int> st2(v, [&](int a, int b) -> int {
		return a + b;
	});
	std::cout << "Passed ability to change the merger function\n";

	// Test that the merger function is actually changed.
	for (const auto &vec: st2()) {
		for (auto x: vec) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "Passed the accessibility test\n";

	// Check how many elements are present in a SparseTable of size 1e5
	constexpr int sz = 1e5;
	std::vector<int> v2(sz);
	std::iota(v2.begin(), v2.end(), 0);
	SparseTable<long long> st3(v2, SparseTable<int>::lcm);
	std::size_t cnt = std::accumulate(st3().begin(), st3().end(), 0LL,
		[](std::size_t a, const auto &b) {
			return a + b.size();
		});
	std::cout << "An array of size " << sz << " has " << cnt << " elements\n";
}
