#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ; cin >> n;
    string s; cin >> s;
    cin >> nQ;

    array<int, 3> p;
    p.fill(-1);

    vector<int> prev(n, -1);
    char c;
    for (int t, x, q = 0; q < nQ; q++) {
        cin >> t >> x >> c;
        x--;
        if (t == 1) {
            s[x] = c;
            prev[x] = q;
        }
        p[t - 1] = q;
    }

    for (int i = 0; i < n; i++) {
        if (p[2] < p[1] and prev[i] < p[1]) {
            prev[i] = p[1];
            s[i] = tolower(s[i]);
        } else if (p[1] < p[2] and prev[i] < p[2]) {
            prev[i] = p[2];
            s[i] = toupper(s[i]);
        }
    }

    cout << s;

    return 0;
}
