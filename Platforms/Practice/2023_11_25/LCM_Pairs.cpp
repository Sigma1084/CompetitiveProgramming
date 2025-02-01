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

    const int N = *max_element(a.begin(), a.end());
    vector<int> cnt(N + 1);

    for (int x: a) {
        ++cnt[x];
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        for (int j = 2*i; j <= N; j += i) {
            ans += 1LL * cnt[i] * cnt[j];
        }
    }

    cout << ans << '\n';

    return 0;
}
