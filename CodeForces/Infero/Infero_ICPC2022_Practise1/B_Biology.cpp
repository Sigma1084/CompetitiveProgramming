#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int A, B; cin >> A >> B;
    int a1, s1, a2, s2;
    cin >> a1 >> s1 >> a2 >> s2;

    if (a1 > a2) {
        swap(a1, a2);
        swap(s1, s2);
    }

    // a2 >= a1

    // 1. Straight Flush
    if (s1 != s2 or a2 - a1 > 4) {
        cout << 0 << ' ';
    } else {
        int rem = 4 + a1 - a2;
        cout << 1 + min(min(A-1, a1 + rem) - a1, a1 - max(0, a1 - rem)) << ' ';
    }

    // 2. Four of a Kind
    if (B == 4 and a1 == a2) {
        cout << (A-1) * B << ' ';
    } else if (B == 4) {
        cout << 2 << ' ';
    } else {
        cout << 0 << ' ';
    }

    // 3. Full House
    if (B < 3) {
        cout << 0 << ' ';
    } else if (a1 == a2) {
        if (B == 4) {
            cout << 2 + 4*(A-1) << ' ';
        } else {
            cout << 1 + 3*(A-1) << ' ';
        }
    } else {
        if (B == 4) {
            cout << 8 << ' ';
        } else {
            cout << 4 << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

