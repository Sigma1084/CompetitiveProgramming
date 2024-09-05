#pragma once

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using __ordered_mset = __gnu_pbds::tree<T,
	__gnu_pbds::null_type,
	std::less_equal<T>,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template<typename T>
struct OrderedMultiset: __ordered_mset<T> {
	using __ordered_mset<T>::__ordered_mset;

	/**
	 * less_equal operator interchanges lower_bound and upper_bound
	 */

	int count(T val) const {
		return this->order_of_key(val + 1) - this->order_of_key(val);
	}

	void eraseOne(T val) {
		if (count(val)) {
			this->erase(this->upper_bound(val));
		}
	}

	void eraseAll(T val) {
		for (int i = count(val); i; i--) {
			this->erase(this->upper_bound(val));
		}
	}

	int order_of_key_first(T val) {
		return this->order_of_key(val);
	}

	int order_of_key_last(T val) {
		return this->order_of_key(val + 1) - 1;
	}
};
