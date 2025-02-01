#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace sieve {
    template<unsigned int N>
    constexpr std::array<unsigned int, N + 1> getLPF() {
        std::array<unsigned int, N + 1> lPF;
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

    template<unsigned int N>
    std::vector<int> getPrimes(const std::array<unsigned int, N + 1> &_lPF) {
        std::vector<int> primes;
        for (unsigned int i = 2; i <= N; ++i) {
            if (_lPF[i] == i) {
                primes.push_back(i);
            }
        }
        return primes;
    }
}  // namespace sieve

constexpr int N = 1'000'000;
const auto lPF = sieve::getLPF<N>();
const auto primes = sieve::getPrimes<N>(lPF);

std::array<ll, N + 1> getPhi() {
    std::array<ll, N + 1> phi;
    std::iota(phi.begin(), phi.end(), 0);
    for (int p : primes) {
        for (int i = p; i <= N; i += p) {
            phi[i] -= phi[i] / p;
        }
    }
    return phi;
}
const auto phi = getPhi();

std::array<ll, N + 1> prec() {
    std::array<ll, N + 1> ans;
    for (int d = 1; d <= N; ++d) {
        for (int n = 2 * d; n <= N; n += d) {
            ans[n] += d * phi[n / d];
        }
    }
    std::partial_sum(ans.cbegin(), ans.cend(), ans.begin());
    return ans;
}
const auto ans = prec();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        cout << ans[n] << '\n';
    }

    return 0;
}
