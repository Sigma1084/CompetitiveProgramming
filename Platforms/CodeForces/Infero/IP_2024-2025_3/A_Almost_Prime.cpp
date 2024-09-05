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

}  // namespace sieve
using sieve::lPF, sieve::primes;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    while (n > 1) {
        int ps = 0;
        int m = n;
        while (m > 1) {
            int p = lPF[m];
            ++ps;
            while (m % p == 0) {
                m /= p;
            }
        }
        ans += ps == 2;
        --n;
    }

    cout << ans << '\n';

    return 0;
}
