#include <LazySegmentTree.hpp>
#include <cassert>
#include <iostream>
#include <numeric>

int main() {
	constexpr int n = 5;
	std::vector<int> v(n);
	std::iota(v.begin(), v.end(), 1);
	LazySegmentTreeAdd st(n);
	st.assign(v);

	for (int i = 0; i < n; i++) {
		assert(st.query(i, i) == i + 1);
	}
	std::cout << "Passed query (i, i) test\n";

	for (int i = 0; i < n; i++) {
		assert(st.query(0, i) == (i + 1) * (i + 2) / 2);
	}
	std::cout << "Passed query (0, i) test\n";

	st.update(0, 2, 1);
	for (int i = 0; i < n; i++) {
		assert(st.query(i, i) == i + 1 + int(i <= 2));
	}
	std::cout << "Passed addInRange(0, 2, 1) test\n";

	return 0;
}
