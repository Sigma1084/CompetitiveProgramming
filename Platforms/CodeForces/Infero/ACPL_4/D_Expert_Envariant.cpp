#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mn(int n, int k) {
    return (n / 2) * (1 - k) + (n % 2) * 1;
}

int mx(int n, int k) {
    return (n / 2) * (k - 1) + (n % 2) * k;
}

bool isPos(int n, int k, int s) {
    return mn(n, k) <= s and s <= mx(n, k);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s, k;
    cin >> n >> s >> k;

    if (mx(n, k) < s or s < mn(n, k)) {
        cout << -1;
        return 0;
    }

    while (n > 2 + (n % 2)) {
        // Can we delete the first 2?
        if (isPos(n - 2, k, s)) {
            cout << 1 << ' ' << 1 << ' ';
            n -= 2;
        } else if (isPos(n - 2, k, s - (k - 1))) {
            cout << k << ' ' << 1 << ' ';
            s -= k - 1;
            n -= 2;
        } else if (isPos(n - 2, k, s + (k - 1))) {
            cout << 1 << ' ' << k << ' ';
            s += k - 1;
            n -= 2;
        } else {
            assert(false);
        }
    }

    // n is at most 2

    return 0;
}
