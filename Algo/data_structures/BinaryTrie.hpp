#include <array>
#include <iostream>
#include <stack>

class BinaryTrie {
public:
	struct Node: std::array<Node*, 2> {
		int weight;  // Number of nodes below it
		Node(): std::array<Node *, 2>({nullptr, nullptr}), weight(0) {}
	};

private:
	Node* root;
	const int maxBitLen;

	void _print(Node *cur, std::string pref, std::iostream &io) const {
		if (cur == nullptr) return;
		io << cur->weight << " ";
		_print(cur->at(0), pref + ' ', io);
		_print(cur->at(1), pref + ' ', io);
	}

public:
	BinaryTrie(int maxBitLen = 32): root(new Node()) ,maxBitLen(maxBitLen) {}

	void insert(int x) {
		Node *curr = root;
		root->weight++;
		for (int i = maxBitLen - 1; i >= 0; --i) {
			int bit = (x >> i) & 1;
			if (curr->at(bit) == nullptr) curr->at(bit) = new Node();
			curr = curr->at(bit);
			curr->weight++;
		}
	}

	int closest(int x) const {
		Node* curr = root;
		int ans = 0;
		for (int i = maxBitLen - 1; i >= 0; --i) {
			int bit = (x >> i) & 1;
			if (!curr->at(bit ^ 1) or curr->at(bit ^ 1)->weight == 0) {
				ans |= (1 << i);
				curr = curr->at(bit ^ 1);
			} else {
				curr = curr->at(bit);
			}
		}
		return ans;
	}

	int farthest(int x) const {
		return closest(~x);
	}

	std::iostream& operator << (std::iostream &io) const {
		_print(root, "", io);
		return io;
	}
};
