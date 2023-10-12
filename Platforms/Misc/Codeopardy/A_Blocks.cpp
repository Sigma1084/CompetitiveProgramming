#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> ops;

    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == 'B') continue;
        s[i] = 'B';
        s[i + 1] ^= 'W' ^ 'B';
        ops.push_back(i);
    }

    if (s.back() == 'B') {
        cout << ops.size() << '\n';
        for (int i : ops) cout << i + 1 << ' ';
        return 0;
    }

    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == 'W') continue;
        s[i] = 'W';
        s[i + 1] ^= 'W' ^ 'B';
        ops.push_back(i);
    }

    if (s.back() == 'W') {
        cout << ops.size() << '\n';
        for (int i : ops) cout << i + 1 << ' ';
        return 0;
    }

    cout << -1 << '\n';

    return 0;
}
