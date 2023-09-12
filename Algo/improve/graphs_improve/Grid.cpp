#include "graphs.hpp"

class GridIterator {
	using DiffType = std::pair<signed char, signed char>;
public:
	constexpr static std::array<DiffType, 4> edges = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	};

	constexpr static std::array<DiffType, 8> full = {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
		 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
	};

	template<class U>
	constexpr static std::array<std::array<U, 2>, 4>
			iterateEdges(int x, int y) {
		return {{
			{{x + 1, y}}, {{x - 1, y}}, {{x, y + 1}}, {{x, y - 1}}
		}};
	}

	template<class U>
	constexpr static std::array<std::array<U, 2>, 8>
			iterateFull(int x, int y) {
		return {{
			{{x + 1, y}}, {{x - 1, y}}, {{x, y + 1}}, {{x, y - 1}},
			{{x + 1, y + 1}}, {{x + 1, y - 1}},
			{{x - 1, y + 1}}, {{x - 1, y - 1}}
		}};
	}
};

template<typename T>
class Grid: public std::vector<std::vector<T>> {
	const std::size_t n, m;
	using Base = std::vector<std::vector<T>>;

public:
	class Iterator {
		using DiffType = std::pair<short int, short int>;
	public:
		constexpr static std::array<DiffType, 4> edges = {
			{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
		};

		constexpr static std::array<DiffType, 8> full = {
			{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
			 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
		};

		template<class U>
		constexpr static std::array<std::array<U, 2>, 4>
		        iterateEdges(int x, int y) {
			return {{
				{{x + 1, y}}, {{x - 1, y}}, {{x, y + 1}}, {{x, y - 1}}
			}};
		}

		template<class U>
		constexpr static std::array<std::array<U, 2>, 8>
		        iterateFull(int x, int y) {
			return {{
				{{x + 1, y}}, {{x - 1, y}}, {{x, y + 1}}, {{x, y - 1}},
				{{x + 1, y + 1}}, {{x + 1, y - 1}},
				{{x - 1, y + 1}}, {{x - 1, y - 1}}
			}};
		}
	};
	using Node = std::pair<std::size_t, std::size_t>;

	Grid(int n, int m, bool makeVector = true): n(n), m(m) {
		if (makeVector) this->resize(n, std::vector<T>(m));
	}

	bool isValid(int x, int y) const {
		return 0 <= x and x < n and 0 <= y and y < m;
	}

	std::vector<Node> edgeIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: Iterator::edges) {
			if (isValid(x + dx, y + dy)) {
				edges.emplace_back(x + dx, y + dy);
			}
		}
		return edges;
	}

	std::vector<Node> fullIterator(int x, int y) const {
		std::vector<Node> edges;
		for (auto [dx, dy]: Iterator::full) {
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
