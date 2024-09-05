#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    // constexpr int N = 2e5;
    // cout << 1 << '\n';
    // cout << N << ' ' << N << '\n';
    // for (int i = 1; i <= N; ++i) {
    //     cout << N << " \n"[i == N];
    // }
    // for (int i = 1; i <= N; ++i) {
    //     cout << 1 << " \n"[i == N];
    // }

    constexpr int A = 2e5;
    constexpr ull INF = numeric_limits<ull>::max();

    ull l = 1, h = (ll) numeric_limits<ll>::max() - 100;

    for (int i = 0; i < 50; ++i) {
        ull m = l + (h - l) / 2;
        h = m - 1;

        ull k = numeric_limits<ull>::max() / m;
        cerr << "m: " << m << ", k: " << k << ", INF - m * k: " << INF - m * k << '\n';
        if ((INF - m * k) + m > A) {
            continue;
        }

        ull n = (k + A - 1) / A;
        if (n > 2e5) {
            break;
        }

        vector<int> a(n, A);
        a.back() = k % A;

        cerr << "m: " << m << ", n: " << n << ", k: " << k << '\n';
    }

    // constexpr int M = 16383;
    // Find the min k such that M * k <= numeric_limits<ull>::max()
    // constexpr ull k = 1 + numeric_limits<ull>::max() / M;
    // cout << k << '\n';

    // constexpr int N = (k + A - 1) / A;
    // vector<int> a(N, A);
    // a.back() = k % A;

    // cerr << N << ' ' << A << '\n';

    // cout << 1 << '\n';
    // cout << N << ' ' << A << '\n';
    // for (int i = 0; i < N; ++i) {
    //     cout << a[i] << " \n"[i == N - 1];
    // }
}