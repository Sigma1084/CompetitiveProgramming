#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int A = 1e6;
array<int, A + 1> f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    // block size
    int k = n / sqrt(n);

    vector<array<int, 3>> b(nQ);
    vector<ll> ans(nQ);
    for (auto &[l, r, ind]: b) {
        cin >> l >> r;
        --l, --r;
    }
    for (int i = 0; i < nQ; ++i) {
        b[i][2] = i;
    }
    sort(b.begin(), b.end(), [k](const auto &x, const auto &y) {
        if (x[0] / k != y[0] / k) {
            return x[0] < y[0];
        }
        return x[1] < y[1];
    });

    int ind = 0;
    ll cur = 0;

    for (int i = 0; k*i < n and ind < nQ; ++i) {        
        // We need to reset f
        f.fill(0);
        cur = 0;

        // Special cases where start and end are in the same block
        while (ind < nQ and b[ind][0] / k == i and b[ind][1] / k == i) {
            // brute force
            for (int x = b[ind][0]; x <= b[ind][1]; ++x) {
                cur -= 1LL * f[a[x]] * f[a[x]] * a[x];
                f[a[x]] += 1;
                cur += 1LL * f[a[x]] * f[a[x]] * a[x];
            }
            ans[b[ind][2]] = cur;
            for (int x = b[ind][0]; x <= b[ind][1]; ++x) {
                cur -= 1LL * f[a[x]] * f[a[x]] * a[x];
                f[a[x]] -= 1;
                cur += 1LL * f[a[x]] * f[a[x]] * a[x];
            }
            ++ind;
        }

        for (int j = i + 1; k*j < n; ++j) {
            // Those whose start is in i-th block and end in j-th
            int y = k * j;

            // Do the things
            while (ind < nQ and b[ind][0] / k == i and b[ind][1] / k == j) {
                // brute force indeed
                for (int x = b[ind][0]; x < k*(i + 1); ++x) {
                    cur -= 1LL * f[a[x]] * f[a[x]] * a[x];
                    f[a[x]] += 1;
                    cur += 1LL * f[a[x]] * f[a[x]] * a[x];
                }
                for (; y <= b[ind][1]; ++y) {
                    cur -= 1LL * f[a[y]] * f[a[y]] * a[y];
                    f[a[y]] += 1;
                    cur += 1LL * f[a[y]] * f[a[y]] * a[y];
                }
                ans[b[ind][2]] = cur;
                for (int x = b[ind][0]; x < k*(i + 1); ++x) {
                    cur -= 1LL * f[a[x]] * f[a[x]] * a[x];
                    f[a[x]] -= 1;
                    cur += 1LL * f[a[x]] * f[a[x]] * a[x];
                }
                ++ind;
            }

            // Adding the remaining
            for (; y <= b[ind][1]; ++y) {
                cur -= 1LL * f[a[y]] * f[a[y]] * a[y];
                f[a[y]] += 1;
                cur += 1LL * f[a[y]] * f[a[y]] * a[y];
            }
        }
    }

    for (auto x: ans) {
        cout << x << '\n';
    }

    return 0;
}
