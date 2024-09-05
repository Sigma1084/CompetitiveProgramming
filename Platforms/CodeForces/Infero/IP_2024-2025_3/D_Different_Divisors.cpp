#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace sieve {
    template<unsigned int N>
    constexpr std::array<int, N + 1> getLPF() {
        std::array<int, N + 1> lPF;
        std::iota(lPF.begin(), lPF.end(), 0);
        lPF[0] = lPF[1] = -1;
        for (unsigned int i = 2; i * i <= N; ++i) {
            if (lPF[i] != i) continue;
            for (unsigned int j = i * i; j <= N; j += i) {
                if (lPF[j] == j) lPF[j] = i;
            }
        }
        return lPF;
    }
    constexpr int N = 1'000'000;
    const std::array<int, N + 1> lPF = getLPF<N>();

    std::vector<int> getPrimes() {
        std::vector<int> primes;
        for (unsigned int i = 2; i <= N; ++i) {
            if (lPF[i] == i) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    const std::vector<int> primes = getPrimes();
}
using sieve::lPF, sieve::primes;

void solve() {
    int d;
    cin >> d;

    int p = *lower_bound(primes.begin(), primes.end(), d + 1);
    int q = *lower_bound(primes.begin(), primes.end(), p + d);

    cout << 1LL * p * q;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
