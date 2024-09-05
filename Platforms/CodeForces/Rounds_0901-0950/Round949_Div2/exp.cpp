#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {5, 4, 3, 2, 1};

    auto &v = a;
    for (int i = 0; i < 5; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    v = b;
    for (int i = 0; i < 5; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}
