#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto t = s;
    reverse(t.begin(), t.end());

    if (t < s) {
        swap(s, t);
        n--;
    }

    n %= 2;
    if (n) {
        s += t;
    }

    cout << s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
