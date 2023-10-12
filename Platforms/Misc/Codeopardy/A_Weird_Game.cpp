#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    n *= 2;

    string a, b;
    cin >> a >> b;

    int both = 0, alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '1') both++;
        else if (a[i] == '1') alice++;
        else if (b[i] == '1') bob++;
    }

    // They will do both
    both %= 2;
    bob -= both;

    if (alice > bob) {
        cout << "First";
    } else if (bob > alice + 1) {
        cout << "Second";
    } else {
        cout << "Draw";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
