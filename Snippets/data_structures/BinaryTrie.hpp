#include <array>
#include <iostream>
#include <string>

class BinaryTrie {
public:
    struct Node : std::array<Node *, 2> {
        int weight;
        Node() : std::array<Node *, 2>({nullptr, nullptr}), weight(0) {}
    };

private:
    Node *root;
    const int maxBitLen;

    void _print(Node *cur, std::string &pref, std::ostream &out) const {
        if (cur == nullptr) return;
        out << pref << std::string(maxBitLen - pref.size(), '_');
        out << ": " << cur->weight << '\n';
        pref += '0';
        _print(cur->at(0), pref, out);
        pref.pop_back();
        pref += '1';
        _print(cur->at(1), pref, out);
        pref.pop_back();
    }

public:
    explicit BinaryTrie(short maxBitLen = 32)
        : root(new Node()), maxBitLen(maxBitLen) {}

    void insert(int x) {
        Node *curr = root;
        curr->weight++;
        for (int i = maxBitLen - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (curr->at(bit) == nullptr) { curr->at(bit) = new Node(); }
            curr = curr->at(bit);
            curr->weight++;
        }
    }

    [[nodiscard]] int closest(int x) const {
        Node *curr = root;
        int ans = 0;
        for (int i = maxBitLen - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (curr->at(bit) != nullptr and curr->at(bit)->weight > 0) {
                ans += bit << i;
                curr = curr->at(bit);
            } else {
                ans += (1 - bit) << i;
                curr = curr->at(1 - bit);
            }
        }
        return ans;
    }

    [[nodiscard]] int farthest(int x) const {
        return closest((1 << maxBitLen) - 1 - x);
    }

    friend std::ostream &operator<<(std::ostream &out, const BinaryTrie &trie) {
        std::string pref;
        trie._print(trie.root, pref, out);
        return out;
    }
};