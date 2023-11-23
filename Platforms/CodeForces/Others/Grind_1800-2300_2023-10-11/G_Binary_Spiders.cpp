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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n << '\n';
        for (int i = 1, x; i <= n; ++i) {
            cin >> x;
            cout << i << ' ';
        }
        return 0;
    }

    // Count the number of bits
    int mL = std::__lg(k);
    int m = 1 << mL;

    /**
     * mp[class] = [{value, index}]
     */
    map<int, vector<array<int, 2>>> mp;
    for (int i = 1, x, c, v; i <= n; ++i) {
        cin >> x;
        c = x / (2*m);
        v = x % (2*m);
        mp[c].push_back({v, i});
    }

    vector<int> ans;

    for (auto &[c, a] : mp) {
        BinaryTrie trie(mL + 1);
        for (auto [v, i] : a) {
            trie.insert(v);
        }

        cerr << trie << '\n';

        bool ok = false;
        for (auto [v, i] : a) {
            int x = trie.farthest(v);
            if ((x ^ v) < k) continue;

            for (auto [v2, i2]: a) {
                if (v2 == x) {
                    ans.push_back(i);
                    ans.push_back(i2);
                    ok = true;
                    break;
                }
            }
            break;
        }

        if (not ok) {
            ans.push_back(a[0][1]);
        }
    }

    if (ans.size() == 1) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
