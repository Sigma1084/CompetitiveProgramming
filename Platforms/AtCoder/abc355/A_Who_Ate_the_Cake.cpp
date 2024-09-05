#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a != b) {
        cout << 6 - a - b;
    } else {
        cout << -1;
    }

    return 0;
}
