#include <vector>
#include <array>
#include <algorithm>

class LIS {
	using arr2 = std::array<int, 2>;
	static bool compSecond(arr2 a, arr2 b) {
		return a[1] < b[1];
	}

public:
	std::vector<std::vector<int>> fullArr;
	std::vector<arr2> lastEles;

    LIS(const std::vector<int> &a) {
		for (auto &i: a) {
			auto lb = std::lower_bound(lastEles.begin(), lastEles.end(), 
				arr2{i, 0}, std::greater<arr2>());
			if (lb == lastEles.end()) {
				lastEles.push_back( {i, 1} );
			} else {
				*lb = { i, (*lb)[1] + 1 };
			}
		}
	}

	int max_freq() const {
		return max_element(lastEles.begin(), lastEles.end(),
            compSecond)->at(1);
	}
};