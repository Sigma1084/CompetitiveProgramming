#include <bits/stdc++.h>
using namespace std;

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
            if (curr->at(bit) == nullptr or curr->at(bit)->weight == 0) {
                if (!bit) {
                    ans |= (1 << i);
                }
                curr = curr->at(bit ^ 1);
            } else {
                if (bit) {
                    ans |= (1 << i);
                }
                curr = curr->at(bit);
            }
        }
        return ans;
    }

    int farthest(int x) const {
        Node* curr = root;
        int ans = 0;
        for (int i = maxBitLen - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (curr->at(1 ^ bit) != nullptr and curr->at(1 ^ bit)->weight > 0) {
                ans += (1 ^ bit) * (1 << i);
                curr = curr->at(1 ^ bit);
            } else {
                ans += (bit) * (1 << i);
                curr = curr->at(bit);
            }
        }
        return ans;
    }

    void print(std::ostream &out) const {
        _print(root, "", out);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int &x: a) {
        cin >> x;
    }

    BinaryTrie trie;
    vector<int> b(n);
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] ^ a[i - 1];
    }

    for (int x: b) {
        trie.insert(x);
    }

    // Keep track of the max element
    for (int i = 0; i < n; ++i) {
        int x = trie.farthest(b[i]);
        if ((b[i] ^ x) <= n - 1) {
            for (int y: b) {
                cout << (b[i] ^ y) << ' ';
            }
            cout << '\n';
            break;
        }
    }

    return 0;
}
