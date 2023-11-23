#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for (int &x: p | views::drop(1)) {
        cin >> x;
        x--;
    }

    return 0;
}