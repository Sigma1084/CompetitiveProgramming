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

constexpr int N = 1'000'000;
const auto lPF = getLPF<N>();
const auto primes = getPrimes<N>(lPF);

}  // namespace sieve
using sieve::lPF, sieve::primes;

void solve() {
    int n;
    cin >> n;

    int ans = 1;
    while (n > 1) {
        int p = lPF[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        ans *= cnt + 1;
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
