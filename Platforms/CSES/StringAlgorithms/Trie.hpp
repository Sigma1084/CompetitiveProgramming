#include <array>
#include <vector>

template <typename T, unsigned int N, std::array<T, N>>
class Trie {
protected:
    using Index = unsigned int;
    struct TrieNode: public std::array<TrieNode*, N> {
        using std::array<TrieNode*, N>::array;
    };

    Index getIndex(T t);

private:
    TrieNode* root;

public:
    void insert(const std::vector<T> &v) {
        TrieNode *node = root;
        for (const T &t : v) {
            Index i = getIndex(t);
            if (node->at(i) == nullptr) {
                node->at(i) = new TrieNode();
            }
            node = node->at(i);
        }
    }
};
