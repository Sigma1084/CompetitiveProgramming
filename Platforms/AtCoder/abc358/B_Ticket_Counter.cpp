#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int cur = 0;
    for (auto x: a) {
        if (cur < x) {
            cur = x;
        }
        cout << (cur += t) << '\n';
    }

    return 0;
}
