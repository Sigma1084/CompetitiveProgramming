#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <cassert>
using ll = long long int;
constexpr ll INF = 1e18;


// Grid Iterator
template<typename T>
class Grid;


// Single Source - Shortest Paths (SSSP) (positive edges) O(n log n + m)
std::vector<ll> dijkstra(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source);

// All pairs shortest paths (no negative cycles) O(n^3)
std::vector<std::vector<ll>> floydWarshall(
		const std::vector<std::vector<std::array<int, 2>>> &graph);


// Single Source - Shortest Paths (SSSP) (arbitrary edges) O(n * m)
std::vector<ll> bellmanFord(
		const std::vector<std::vector<std::array<int, 2>>> &graph,
		int source);
