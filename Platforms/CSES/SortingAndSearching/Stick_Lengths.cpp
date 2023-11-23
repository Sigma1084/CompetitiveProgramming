#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    ll ans = std::accumulate(a.begin(), a.end(), 0LL,
        [&](ll acc, int x) {
            return acc + abs(x - a[n/2]);
        });
    cout << ans;

    return 0;
}
