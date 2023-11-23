#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = (a[i] - i + n - 1) / n;
    }

    cout << min_element(a.begin(), a.end()) - a.begin() + 1;

    return 0;
}
