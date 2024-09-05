#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    array<int, 2019> f{};
    f[0] = 1;

    ll ans = 0;
    for (int i = s.size() - 1, j = 1, x = 0; i >= 0; --i) {
        x += (s[i] - '0') * j;
        x %= 2019;
        ans += f[x]++;
        j = j * 10 % 2019;
    }

    cout << ans << '\n';

    return 0;
}
