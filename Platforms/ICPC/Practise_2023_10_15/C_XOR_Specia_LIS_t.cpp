#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 1 and is_sorted(all(a)) and set(all(a)).size() == a.size()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
