#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> added(n);
    ll numPrev = 0, sub = 0, req;

    for (int i = n-1; i >= 0; --i) {
        // We add it to [i-k+1]
        k = min(k, i+1);

        a[i] = max(0LL, a[i] - sub);
        req = (a[i] + k - 1) / k;

        added[i-k+1] += req;
        sub += k * req;
        numPrev += req;

        sub -= numPrev;
        numPrev -= added[i];
    }

    cout << accumulate(added.begin(), added.end(), 0LL);

    return 0;
}
