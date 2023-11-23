#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> fr(n + 1);
    int win = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        fr[x] += 1;
        if (fr[x] > fr[win] or fr[x] == fr[win] and x < win) {
            win = x;
        }
        cout << win << '\n';
    }

    return 0;
}
