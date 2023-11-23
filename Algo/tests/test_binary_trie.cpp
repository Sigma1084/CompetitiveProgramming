#include <BinaryTrie.hpp>
#include <vector>
#include <cassert>
#include <random>

int main() {
	std::size_t n = 1000;
	std::vector<int> v(n);

	// Setting a seed for the random number generator
	std::mt19937 rng(0);

	// Inserting 1000 random numbers in the trie
	BinaryTrie bt(32);
	for (int i = 0; i < n; ++i) {
		v[i] = rng() / 10;
		bt.insert(v[i]);
	}

	// Print the vector
	std::cerr << "The first 10 elements of the vector: ";
	for (auto x: std::vector(v.begin(), v.begin() + 10)) {
		std::cerr << x << ' ';
	}
	std::cerr << '\n';

	// Checking that the closest and farthest numbers are correct
	for (int i = 0; i < n; ++i) {
		int closest = bt.closest(v[i]), farthest = bt.farthest(v[i]);
		int bruteClosest = v[0], bruteFarthest = v[0];
		for (int j = 0; j < n; ++j) {
			if (abs(v[i] ^ v[j]) < abs(v[i] ^ bruteClosest)) {
				bruteClosest = v[j];
			}
			if (abs(v[i] ^ v[j]) > abs(v[i] ^ bruteFarthest)) {
				bruteFarthest = v[j];
			}
		}
		assert(closest == bruteClosest);
		assert(farthest == bruteFarthest);
	}

	std::cerr << "Passed closest and farthest tests\n";
}
