#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    array<int, 3> b = {0, 0, 0};
    cin >> b[0] >> b[1] >> b[2];
    cin.get();

    array<int, 3> a = {0, 0, 0};
    for (char c; cin.get(c); ) {
        if ('a' <= c and c <= 'z') {
            a[0] += 1;
        } else if ('0' <= c and c <= '9') {
            a[1] += 1;
        } else {
            for (int s: ",-;:.!?") {
                if (c == s) {
                    a[2] += 1;
                    break;
                }
            }
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < 3; ++i) {
        if (a[i] > b[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
