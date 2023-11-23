#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        auto x = mp[s]++;
        if (x == 0) {
            cout << "OK\n";
        } else {
            cout << s << x << '\n';
        }
    }

    return 0;
}
