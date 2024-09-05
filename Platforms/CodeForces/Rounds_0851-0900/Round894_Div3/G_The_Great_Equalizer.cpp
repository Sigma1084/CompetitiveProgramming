#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template<typename T>
using ordered_set = __gnu_pbds::tree<T,
	__gnu_pbds::null_type,
	std::less<>,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template<typename T>
using __ordered_mset = __gnu_pbds::tree<T,
	__gnu_pbds::null_type,
	std::less_equal<>,
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
	int count(T val) {
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
		if (count(val)) {
			this->erase(this->upper_bound(val), this->lower_bound(val));
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

/**
 * Consider a0, a1, ... a(n-1) sorted ASC
 * Now, store (1, a1 - a0), (2, a2 - a1) ...
 * The answer will be max of (ai - a(i-1))
 * 
 * Consider 1 4 5 8
 * (1, 3), (2, 1), (3, 3)
 * => 5 7 9  (Added 4 to the first element once)
 * => 8 9 10
 * => 11  (Added 3 to the first element twice)
 * 
 * Consider a map
 * m[1] = 1  (Single contraction) (Add 4 once)
 * m[3] = 2  (Double contraction) (Add 3 twice)
 * 
 * When we alter an element a[i], 2 diffs will change
 * 
 * Suppose the elements are arranged in the order
 * Then, ans = a0 * m[a0] * n + a1 * m[a1] * (n - 1) + ...
 * Suppose m[a1] is decreased by 1
 * If m[a1] is not 1, then the answer is decreased by n - 1
 * Basically n - order(m[a1]) : Number of elements less than a1
 * If m[a1] = 1, then the answer gets increased by the number of
 * elements > a1. (n - order_omset(a1)))
 * 
 * Suppose we have
 * m[a0] * n + m[a1] * (n - 1) + m[a2] * (n - 2) + ...
 * Suppose we want to increase a1 by 1
 * Then, the answer is increased by order_oset(a1)
 * If we do not have the element a1, then we decrease by
 * the number of elements > a1. (n - order_omset(a1))
 * 
 * And then increase by (n - order_set(a1))
 */
void solve() {
    int n; cin >> n;

    vector<int> aReal(n);
    for (int i = 0; i < n; i++) {
        cin >> aReal[i];
    }
	vector<int> a = aReal;
	sort(a.begin(), a.end());

	set<int> s(a.begin(), a.end());
	map<int, int> m;
	ordered_set<int> oset;
	ordered_mset<int> omset;

	for (int i = 1, d; i < n; i++) {
		d = a[i] - a[i - 1];
		omset.insert(d);
		oset.insert(d);
		m[d] += 1;
	}

	ll ans = a[0]; int i, x = n;
	for (auto [d, f]: m) {  // Frequency of diff
		cerr << d << ' ' << f << '\n';
		ans += 1LL * x-- * d;
	}
	cerr << ans << '\n';

	auto insert = [&] (int x) {
		omset.insert(x);
		oset.insert(x);
		m[x] += 1;
		if (m[x] == 1) {
			// Just added
			ans -= (n - omset.order_of_key(x + 1));
		} else {
			// Already present
			ans += n - oset.order_of_key(x); 
		}
	};

	auto erase = [&] (int x) {
		if (m[x] == 1) {
			// Sole element deletion
			ans += (n - omset.order_of_key(x + 1));
		} else {
			// Element still exists
			ans -= n - oset.order_of_key(x);
		}
		m[x] -= 1;
		omset.eraseOne(x);
		if (m[x] == 0) {
			oset.erase(x);
		}
	};

	int nQ; cin >> nQ;
	while (nQ--) {
		cin >> i >> x; i--;
		if (i > 0) {
			erase(a[i] - a[i - 1]);
			insert(x - a[i - 1]);
		}
		if (i < n - 1) {
			erase(a[i + 1] - a[i]);
			insert(a[i + 1] - x);
		}
		a[i] = x;
		cout << ans << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
