#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Compare = std::less<>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> col(n), row(n);
    OSet<int> colSeg, rowSeg;

    for (int t, x, y, x1, y1; nQ--; ) {
        cin >> t >> x >> y;
        --x; --y;

        if (t == 1) {
            if (row[x] == 0) {
                rowSeg.insert(x);
            }
            row[x] += 1;
            if (col[y] == 0) {
                colSeg.insert(y);
            }
            col[y] += 1;
        } else if (t == 2) {
            if (row[x] == 1) {
                rowSeg.erase(x);
            }
            row[x] -= 1;
            if (col[y] == 1) {
                colSeg.erase(y);
            }
            col[y] -= 1;
        } else {
            cin >> x1 >> y1;
            --x1; --y1;
            if (x1 < x) swap(x, x1);
            if (y1 < y) swap(y, y1);
            if (rowSeg.order_of_key(x1 + 1) - rowSeg.order_of_key(x) == x1 - x + 1) {
                cout << "Yes\n";
            } else if (colSeg.order_of_key(y1 + 1) - colSeg.order_of_key(y) == y1 - y + 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
