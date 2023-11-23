#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << '\n';

    return 0;
}
