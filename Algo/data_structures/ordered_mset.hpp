#pragma once

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template<typename T>
using __ordered_mset = __gnu_pbds::tree<T,
	__gnu_pbds::null_type,
	std::less_equal<T>,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

/**
 * @brief Ordered multiset
 * @tparam T Typename
 */
template<typename T>
struct ordered_mset: __ordered_mset<T> {
	using __ordered_mset<T>::__ordered_mset;

	/**
	 * less_equal operator interchanges lower_bound and upper_bound
	 */

	/**
	 * @brief Returns the number of instances of a value
	 * @param val The value to count
	 * @return (int) The number of instances of the value
	 */
	int count(T val) const {
		return this->order_of_key(val + 1) - this->order_of_key(val);
	}

	/**
	 * @brief Erases an instance of a value from the multiset
	 * @param val The value to erase
	 */
	void eraseOne(T val) {
		if (count(val)) {
			this->erase(this->upper_bound(val));
		}
	}

	/**
	 * @brief Erases all instances of a value from the multiset
	 * @param val The value to erase
	 */
	void eraseAll(T val) {
		for (int i = count(val); i; i--) {
			this->erase(this->upper_bound(val));
		}
	}

	/**
	 * @brief Returns the position of the first instance of a value
	 * @param val The value to find
	 * @return (int) The position of the first instance of the value
	 * @note Same as order_of_key
	 */
	int order_of_key_first(T val) {
		return this->order_of_key(val);
	}

	/**
	 * @brief Returns the position of the last instance of a value
	 * @param val The value to find
	 * @return (int) The position of the last instance of the value
	 * @note order_of_key(val + 1) - 1
	 */
	int order_of_key_last(T val) {
		return this->order_of_key(val + 1) - 1;
	}
};
