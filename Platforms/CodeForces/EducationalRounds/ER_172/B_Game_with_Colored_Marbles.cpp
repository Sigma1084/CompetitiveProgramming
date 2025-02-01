#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x-1]++;
    }

    int numOnes = 0, sc = 0;
    for (int x: a) {
        numOnes += (x == 1);
        sc += bool(x);
    }
    sc += numOnes & 1;

    cout << sc;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
