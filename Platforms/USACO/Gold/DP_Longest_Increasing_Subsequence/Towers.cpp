#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int &x: a) std::cin >> x;

	std::vector<int> stacks;
	for (int i: a) {
		if (stacks.empty() or i >= stacks.back()) {
			// We need to create a new stack
			stacks.push_back(i);
		} else {
			// We can place i on an existing stack which is > i
			*std::upper_bound(stacks.begin(), stacks.end(), i) = i;
		}
	}

	std::cout << stacks.size() << '\n';

	return 0;
}
