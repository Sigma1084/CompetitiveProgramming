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

    void _print(Node *cur, std::string pref, std::ostream &io) const {
        if (cur == nullptr) return;
        io << pref << cur->weight << "\n";
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

    int mex(int x) const {
        Node* curr = root;
        int ans = 0;
        for (int i = maxBitLen - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (curr->at(bit) and curr->at(bit)->weight == (1 << i)) {
                ans |= (1 << i);
                if (curr->at(bit ^ 1) == nullptr) {
                    break;
                }
                curr = curr->at(bit ^ 1);
            } else if (curr->at(bit) == nullptr) {
                break;
            } else {
                curr = curr->at(bit);
            }
        }
        return ans;
    }

    std::ostream& print(std::ostream &os) const {
        _print(root, "", os);
        return os;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    BinaryTrie trie(20);
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (auto &x: set<int>(a.begin(), a.end())) {
        trie.insert(x);
    }

    for (int x = 0, y; nQ--; ) {
        cin >> y;
        x ^= y;
        cout << trie.mex(x) << '\n';
    }

    return 0;
}
