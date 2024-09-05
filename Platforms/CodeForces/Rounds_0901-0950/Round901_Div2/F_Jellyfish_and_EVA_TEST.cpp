#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<double> p = {0, 1, 2, 3, 4, 5};
    auto s = accumulate(p.begin(), p.end(), double(0));
    for (auto &x: p) {
        x /= s;
    }

    std::cerr << std::fixed << std::setprecision(4);
    const int N = p.size();

    function<double(vector<double>)> prob = [&](vector<double> p) {
        int n = p.size();
        if (n == 0) return 0.0;
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            double cur = 0;
            if (n == N)
                cerr << "For i = " << i << '\n';
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    cur += p[i];
                    if (n == N)
                        cerr << "For j = " << j << ", " << p[i] << '\n';
                } else {
                    if (n == N)
                        cerr << "For j = " << j << ", ";
                    vector<double> p2;
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        p2.push_back(p[k]);
                    }
                    cur += prob(p2);
                }
            }
            cur /= n;
            if (n == N)
                cerr << "cur = " << cur << '\n';
            ans = max(ans, cur);
        }

        if (N == n + 2) {
            cerr << "Calling for: ";
            for (auto x: p) cerr << x << ' ';
            cerr << " = " << ans << '\n';
        }

        return ans;
    };

    std::cout << prob(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    // while (t--) {
    //     solve();
    //     cout << '\n';
    // }

    int N = 100;
    using ld = long double;

    vector<vector<ld>> p(N);
    p[2] = {0.5, 0};
    for (int n = 4; n < N; n += 2) {
        p[n].resize(n);
        ld q = 1 / ld(n);
        for (int i = 1; i < n - 1; i++) {
            p[n][i] = ((i - 1 < n - 2 ? p[n - 2][i - 1] : 0) * (n - 1 - i) 
                + (i >= 2 ? p[n - 2][i - 2] : 0) * (i - 1)) * q;
        }
        p[n][0] = q;
    }

    for (int i = 0; i < N; ++i) {
        std::cout << i << ": ";
        for (auto x: p[i]) std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}
