#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


class BinaryNode {
public:
	struct Node: std::array<Node*, 2> {
		int weight;  // Number of nodes below it
		Node(): std::array<Node *, 2>({nullptr, nullptr}), weight(0) {}
	};

private:
	Node* root;
	const int numLen;

	void _print(Node *cur, std::string pref) const {
		if (cur == nullptr) return;
		if (pref.size() == numLen)
			std::cerr << pref << ": " << cur->weight << '\n';
		_print(cur->at(0), pref + '0');
		_print(cur->at(1), pref + '1');
	}

public:
	BinaryNode(int numLen = 32): numLen(numLen), root(new Node()) {}

	void insert(int x) {
		Node* curr = root;
		root->weight++;
		for (int i = numLen - 1; i >= 0; --i) {
			int bit = (x >> i) & 1;
			if (curr->at(bit) == nullptr) {
				curr->at(bit) = new Node();
			}
			curr = curr->at(bit);
			curr->weight++;
		}
	}

	int closest(int x) const {
		Node* curr = root;
		int ans = 0;
		for (int i = numLen - 1; i >= 0; --i) {
			int bit = (x >> i) & 1;
			if (curr->at(bit) != nullptr) {
				ans |= bit ? (1 << i) : 0;
				curr = curr->at(bit);
			} else {
				ans |= bit ? 0 : (1 << i);
				curr = curr->at(bit ^ 1);
			}
		}
		return ans;
	}

	int farthest(int x) const {
		return closest(~x);
	}

	void print() const {
		_print(root, "");
	}
};



/**
 * a1 a2 a3 a4 a5
 * a1 a2 a3 a4 a5 a3^a4^a5
 * a1 a2 a3 a4 a5 a2^a3^a4^a5 a2^a3
 */

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	BinaryNode trie(8);

	int ans = 0, cur = 0;
	trie.insert(0);
	for (int x: a) {
		cur ^= x;
		trie.insert(cur);
		ans = max(ans, cur ^ trie.farthest(cur));
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
