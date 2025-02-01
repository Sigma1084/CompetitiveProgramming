#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a;
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (gcd(n, i) == 1) {
            a.push_back(i);
            p = (1LL * p * i) % n;
        }
    }

    cout << a.size() - (p != 1) << '\n';
    for (int i : a) {
        if (p != 1 and i == p) continue;
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
