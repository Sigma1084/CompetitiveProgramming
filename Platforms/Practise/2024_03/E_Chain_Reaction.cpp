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

    const int A = *max_element(a.begin(), a.end());

    vector<int> p(A + 1);
    for (int i = 0; i < n; ++i) {
        p[a[i]] += (i == 0 or a[i] >= a[i-1]) - (i < n-1 and a[i] <= a[i+1]);
    }
    partial_sum(p.begin(), p.end(), p.begin());

    for (int k = 1; k <= A; ++k) {
        ll ans = 0;
        for (int i = 1; i <= A; i += k) {
            ans += 1LL * (i + k - 1) / k * (p[min(i + k - 1, A)] - p[i - 1]);
        }
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}
