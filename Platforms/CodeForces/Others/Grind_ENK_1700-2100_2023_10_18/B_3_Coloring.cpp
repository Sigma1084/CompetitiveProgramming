#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<array<int, 2>> odds, evens;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i + j) % 2 == 0) {
                evens.push({i, j});
            } else {
                odds.push({i, j});
            }
        }
    }

    auto print = [&](int parity, int color) {
        auto &q = (parity == 0 ? evens : odds);
        auto [i, j] = q.front();
        q.pop();
        cout << color << ' ' << i << ' ' << j << endl;
    };

    int a = 1, b = 2, c = 3;

    while (odds.size() or evens.size()) {
        int d;
        cin >> d;

        // Can use an a
        if (d != a and evens.size()) {
            print(0, a);
            continue;
        }

        // Can use a b
        if (d != b and odds.size()) {
            print(1, b);
            continue;
        }

        // Fill the rest
        if (odds.size()) {
            if (d == b) {
                print(1, c);
            } else {
                print(1, b);
            }
        } else {
            if (d == a) {
                print(0, c);
            } else {
                print(0, a);
            }
        }
    }

    return 0;
}
