#include <ordered_mset.hpp>
#include <vector>
#include <iostream>

int main() {
	ordered_mset<int> s;
	std::vector<int> v = {1, 2, 1, 2, 5};

	for (auto x: v) {
		s.insert(x);
	}

	std::sort(v.begin(), v.end());

	std::cerr << "Array a: ";
	for (auto x: v) {
		std::cerr << x << ' ';
	}
	std::cerr << "\n\n";

	std::cerr << "upper_bound(x) is the first element >= than x\n";
	std::cerr << "Equivalent to lower_bound(x) in a sorted array\n";
	std::cerr << "*upper_bound for 1, 2 and 4:\n";
	for (int x: {1, 2, 4}) {
		std::cerr << (*s.upper_bound(x)) << ' ';
		assert(*s.upper_bound(x) ==
			*std::lower_bound(v.begin(), v.end(), x));
	}
	std::cerr << '\n';
	std::cerr << "Verified upper_bound\n\n";

	std::cerr << "lower_bound(x) is the first element > than x\n";
	std::cerr << "Equivalent to upper_bound(x) in a sorted array\n";
	std::cerr << "*lower_bound for 1, 2 and 4:\n";
	for (int x: {1, 2, 4}) {
		std::cerr << (*s.lower_bound(x)) << ' ';
		assert(*s.lower_bound(x) ==
			*std::upper_bound(v.begin(), v.end(), x));
	}
	std::cerr << '\n';
	std::cerr << "Verified lower_bound\n\n";

	std::cerr << "find_by_order(i), v[i]:\n";
	for (int i = 0; i < v.size(); i++) {
		std::cerr << *s.find_by_order(i) << ' ' << v[i] << "  ";
		assert(*s.find_by_order(i) == v[i]);
	}
	std::cerr << '\n';
	std::cerr << "Verified find_by_order\n\n";

	std::cerr << "order_of_key (num_elements less than) "
				 "for 0, 1, 2, 3, 4, 5, 6:\n";
	for (int i = 0; i <= 6; i++) {
		std::cerr << s.order_of_key(i) << ' ';
		assert(s.order_of_key(i) ==
			std::count_if(v.begin(), v.end(),
				[i](int x) { return x < i; }));
	}
	std::cerr << '\n';
	std::cerr << "Verified order_of_key\n\n";

	std::cerr << "count (number of instances of) "
				 "for 0, 1, 2, 3, 4, 5, 6:\n";
	for (int i = 0; i <= 6; i++) {
		std::cerr << s.count(i) << ' ';
		assert(s.count(i) ==
			std::count(v.begin(), v.end(), i));
	}
	std::cerr << '\n';
	std::cerr << "Verified count\n\n";

	std::cerr << "order_of_key_first (first instance of) "
				 "for 0, 1, 2, 3, 4, 5, 6:\n";
	for (int i = 0; i <= 6; i++) {
		std::cerr << s.order_of_key_first(i) << ' ';
		assert(s.order_of_key_first(i) ==
			std::lower_bound(v.begin(), v.end(), i) - v.begin());
	}
	std::cerr << '\n';
	std::cerr << "Verified order_of_key_first\n\n";

	std::cerr << "order_of_key_last (last instance of) "
				 "for 0, 1, 2, 3, 4, 5, 6:\n";
	for (int i = 0; i <= 6; i++) {
		std::cerr << s.order_of_key_last(i) << ' ';
		assert(s.order_of_key_last(i) ==
			std::upper_bound(v.begin(), v.end(), i) - v.begin() - 1);
	}
	std::cerr << '\n';
	std::cerr << "Verified order_of_key_last\n\n";

	std::cerr << "eraseOne(1):\n";
	s.eraseOne(1);
	for (auto x: s) {
		std::cerr << x << ' ';
	}
	assert(s.count(1) == 1);
	std::cerr << "\n\n";

	std::cerr << "eraseAll(2):\n";
	s.eraseAll(2);
	for (auto x: s) {
		std::cerr << x << ' ';
	}
	assert(s.count(2) == 0);
	std::cerr << "\n\n";

	return 0;
}
