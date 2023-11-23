#include <LCATree.hpp>
#include <cassert>
#include <chrono>
#include <iostream>

void basicTests() {
	const int n = 7;
	std::vector<std::vector<int>> edges = {
			{1, 2, 3},
			{0},
			{0, 4},
			{0, 5},
			{2},
			{3, 6},
			{5}
	};
	LCATree g(edges, 0);

	assert(g.size() == n);
	assert(g.e == edges);

	std::vector<int> p = {0, 0, 0, 0, 2, 3, 5};
	assert(g.p == p);

	std::vector<int> d = {0, 1, 1, 1, 2, 2, 3};
	assert(g.d == d);

	std::vector<int> sz = {7, 1, 2, 3, 1, 2, 1};
	assert(g.sz == sz);

	std::vector<int> tour = {0, 1, 0, 2, 4, 2, 0, 3, 5, 6, 5, 3, 0};
	assert(g.tour == tour);

	std::vector<int> in = {0, 1, 3, 7, 4, 8, 9};
	assert(g.in == in);

	std::vector<int> out = {12, 1, 5, 11, 4, 10, 9};
	assert(g.out == out);

	std::cout << "Passed basic tests for a simple graph with n = 7\n";

	// Testing the LCA part
	g.buildLCA();

	for (int u = 0; u < n; u++) {
		assert(g.lca(u, 0) == 0);
		assert(g.lca(0, u) == 0);
		assert(g.lca(u, u) == u);
	}
	std::cout << "Passed lca(root, u), lca(u, root) and lca(u, u) for all u\n";

	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			std::cout << g.lca(u, v) << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "lca(u, v) printed for all u, v\n";
}

void stressET(int n) {
	std::vector<std::vector<int>> edges(n);
	for (int i = 0; i < n - 1; i++) {
		edges[i].push_back(i + 1);
		edges[i + 1].push_back(i);
	}

	// Time taken to build the Euler Tour
	auto start = std::chrono::high_resolution_clock::now();
	Tree g;
	g.buildET(edges, 0);
	auto end = std::chrono::high_resolution_clock::now();
	auto timeTaken = std::chrono::duration_cast<
	        std::chrono::milliseconds>(end - start).count();
	std::cout << "Time taken to build the Euler Tour for n = " << n << ": "
		<< timeTaken << " ms\n";

	// Memory usage
	std::cout << "Memory usage for n = " << n << ": "
		<< (g.tour.size() + g.in.size() + g.out.size() + g.p.size() +
			g.d.size() + g.sz.size() + g.e.size()) * sizeof(int) / 1024
		<< " KB\n";
}

int main() {
	basicTests();

	// Testing the speed of building the Euler Tour for n = 1e5
	stressET(1e5);
}
