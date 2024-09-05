#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int ans = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[0]) {
            ans = i + 1;
            break;
        }
    }

    cout << ans;

    return 0;
}
