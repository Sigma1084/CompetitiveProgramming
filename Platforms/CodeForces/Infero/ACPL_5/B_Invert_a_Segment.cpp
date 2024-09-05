#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = 1;
    while (i < n and s[i] >= s[i-1]) {
        ++i;
    }

    if (i == n) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << i << " " << i + 1 << "\n";
    }

    return 0;
}
