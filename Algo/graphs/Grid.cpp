#include "graphs.hpp"

template<typename T>
class Grid: public std::vector<std::vector<T>> {
	const std::size_t n, m;
	using Base = std::vector<std::vector<T>>;
	using DiffType = std::pair<short int, short int>;

public:
	using Node = std::pair<std::size_t, std::size_t>;

	constexpr static std::array<DiffType, 4> edgeIteratorDiff = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	};

	constexpr static std::array<DiffType, 8> fullIteratorDiff = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
		 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	};

	Grid(int n, int m, bool makeVector = true): n(n), m(m) {
		if (makeVector) this->resize(n, std::vector<T>(m));
	}

	bool isValid(int x, int y) const {
		return 0 <= x and x < n and 0 <= y and y < m;
	}

	std::vector<Node> edgeIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: edgeIteratorDiff) {
			if (isValid(x + dx, y + dy)) {
				edges.emplace_back(x + dx, y + dy);
			}
		}
		return edges;
	}

	std::vector<Node> fullIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: fullIteratorDiff) {
			if (isValid(x + dx, y + dy)) {
				edges.emplace_back(x + dx, y + dy);
			}
		}
		return edges;
	}

	friend std::ifstream &operator >> (std::ifstream &in, const Grid &grid) {
		for (auto &row: grid) {
			for (auto &cell: row) {
				in >> cell;
			}
		}
		return in;
	}
};
