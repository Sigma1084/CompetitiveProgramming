#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Define a vector
    vector<int> x;
    
    // Adding elements to a vector
    for (int i = 2; i <= 10; i += 2) {
        x.push_back(i);
    }
    // 2 4 6 8 10

	// Traversing a vector
	for (auto &e: x) {
		cout << e << ' ';
	}
	cout << '\n'; // Printing a newline

    return 0;
}
