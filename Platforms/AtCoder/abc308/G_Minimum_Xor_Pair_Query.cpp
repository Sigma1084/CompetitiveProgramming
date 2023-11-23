#include <bits/stdc++.h>
using namespace std;

class BinaryTrie {
public:
    constexpr static int INF = INT_MAX;

    struct Node: std::array<Node*, 3> {
        int weight, level, ans;
        explicit Node(int level):
            std::array<Node *, 3>({nullptr, nullptr, nullptr}),
            weight(0), level(level), ans(INF) {}

        friend std::ostream& operator << (std::ostream &out, const Node &node) {
            out << "w=" << node.weight << ", ";
            out << "l=" << node.level << ", ";
            out << "ans=" << node.ans;
            return out;
        }
    };

protected:
    virtual void _print(Node *cur, const std::string &pref,
                        std::ostream &out) const {
        if (cur == nullptr) return;
        out << pref << ": " << *cur << '\n';
        if (cur->weight == 0) return;
        _print(cur->at(0), pref + '0', out);
        _print(cur->at(1), pref + '1', out);
    }

public:
    const int maxBitLen;
    Node* root;

    explicit BinaryTrie(int maxBitLen = 32):
        maxBitLen(maxBitLen), root(new Node(maxBitLen)) {}

    [[nodiscard]] int closest(int x, Node *cur = nullptr) const {
        if (cur == nullptr) cur = root;
        int ans = 0;
        for (int level = cur->level - 1; level >= 0; --level) {
            int bit = (x >> level) & 1;
            if (cur->at(bit) and cur->at(bit)->weight > 0) {
                if (bit) ans |= (1 << level);
                cur = cur->at(bit);
            } else {
                if (!bit) ans |= (1 << level);
                cur = cur->at(bit ^ 1);
            }
        }
        return ans;
    }

    void update(Node *cur) const {
        cur->ans = cur->weight > 1 ? 0 : INF;
        cur = cur->at(2);
        for (int level = 0; level < maxBitLen; ++level, cur = cur->at(2)) {
            cur->ans = INF;
            Node *l = cur->at(0), *r = cur->at(1);
            if (l and l->weight) {
                cur->ans = min(cur->ans, l->ans);
            }
            if (r and r->weight) {
                cur->ans = min(cur->ans, r->ans);
            }
            if (l and l->weight == 1 and r and r->weight == 1) {
                int pos = closest(0, l) ^ closest(0, r);
                cur->ans = min(cur->ans, pos + (1 << level));
            }
        }
    }

    void insert(int x, int w = 1) const {
        Node *cur = root, *par;
        root->weight += w;
        for (int level = maxBitLen - 1; level >= 0; --level) {
            int bit = (x >> level) & 1;
            if (cur->at(bit) == nullptr) {
                cur->at(bit) = new Node(level);
            }
            par = cur;
            cur = cur->at(bit);
            cur->at(2) = par;
            cur->weight += w;
        }
        update(cur);
    }

    [[nodiscard]] int farthest(int x, Node *cur = nullptr) const {
        return closest((1 << maxBitLen) - 1 - x, cur);
    }

    // Overload operator << for debugging
    friend std::ostream& operator << (std::ostream &out,
                                    const BinaryTrie &trie) {
        trie._print(trie.root, "", out);
        return out;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nQ; cin >> nQ;
    BinaryTrie trie(30);

    for (int t, x; nQ--; ) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            trie.insert(x, 1);
        } else if (t == 2) {
            cin >> x;
            trie.insert(x, -1);
        } else if (t == 3) {
             cout << trie.root->ans << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}
