#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
	void assign( K const& keyBegin, K const& keyEnd, V_forward&& val )
		requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
	{
		// If the interval is empty, do nothing
		if (!(keyBegin < keyEnd))
			return;

		// Store the final value of the last iterator, this must not change
		auto lastVal = operator[](keyEnd);

		// Assign the new value if necessary
		if (!(operator[](keyBegin) == val))
			m_map.insert_or_assign(keyBegin, std::forward<V_forward>(val));

		// Find the first and last iterator to be deleted and delete them
		auto begin = m_map.upper_bound(keyBegin);
		auto end = m_map.upper_bound(keyEnd);
		m_map.erase(begin, end);

		// Assign the final value if necessary
		if (!(operator[](keyEnd) == lastVal))
			m_map.insert_or_assign(keyEnd, lastVal);
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

#include <iostream>

struct K {
    int key;

    // Parameterized constructor
    K(int k) : key(k) {}

    // Copy constructor
    K(const K& other) = default;

    // Move constructor
    K(K&& other) noexcept = default;

    // Copy assignment operator
    K& operator=(const K& other) = default;

    // Move assignment operator
    K& operator=(K&& other) noexcept = default;

    // Less-than operator
    bool operator<(const K& other) const {
        return key < other.key;
    }
};

struct V {
	char val;

	// Parameterized constructor
	V(char v) : val(v) {}

	// Copy constructor
	V(const V& other) = default;

	// Move constructor
	V(V&& other) noexcept = default;

	// Copy assignment operator
	V& operator=(const V& other) = default;

	// Move assignment operator
	V& operator=(V&& other) noexcept = default;

	// Equality operator
	bool operator==(const V& other) const {
		return val == other.val;
	}

	// Print
	friend std::ostream& operator<<(std::ostream& os, const V& v) {
		os << v.val;
		return os;
	}
};

void print(const interval_map<K, V>& map) {
	for (int i = 0; i < 12; ++i) {
		std::cout << map[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void IntervalMapTest() {
	V val('A');
	interval_map<K, V> map(val);
	std::cout << "Initial map: " << std::endl;
	print(map);

	map.assign(K(1), K(3), V('B'));
	std::cout << "After assigning 1-3 to B: " << std::endl;
	print(map);

	map.assign(K(2), K(4), V('C'));
	std::cout << "After assigning 2-4 to C: " << std::endl;
	print(map);

}

int main() {
	IntervalMapTest();
	return 0;
}
