#pragma once

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

	void _print(Node *cur, std::string pref, std::ostream &out) const {
		if (cur == nullptr) return;
		out << pref << ": " << cur->weight << '\n';
		_print(cur->at(0), pref + '0', out);
		_print(cur->at(1), pref + '1', out);
	}

public:
	BinaryTrie(int maxBitLen = 32): root(new Node()), maxBitLen(maxBitLen) {}

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
			if (curr->at(bit) and curr->at(bit)->weight > 0) {
				if (bit) ans |= (1 << i);
				curr = curr->at(bit);
			} else {
				if (!bit) ans |= (1 << i);
				curr = curr->at(bit ^ 1);
			}
		}
		return ans;
	}

	int farthest(int x) const {
		return closest((1 << maxBitLen) - 1 - x);
	}

	// Overload operator << for debugging
	friend std::ostream& operator << (std::ostream &out, const BinaryTrie &trie) {
		trie._print(trie.root, "", out);
		return out;
	}
};
