#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    // Construct the k string
    for (int i = 0; i < k; ++i) {
        s += 'a' + i;
        for (int j = i + 1; j < k; ++j) {
            s += 'a' + i;
            s += 'a' + j;
        }
    }

    while (s.size() < n) {
        s += s;
    }

    s.resize(n);
    cout << s;

    return 0;
}
