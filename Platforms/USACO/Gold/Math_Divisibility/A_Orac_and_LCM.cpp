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
    constexpr auto getPrimes(const std::array<unsigned int, N + 1> &_lPF) {
        std::vector<unsigned int> primes;
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    
    int x;
    vector<int> s(N + 1), sS(N + 1);

    cin >> x;
    for (int p : primes) {
        int e = 0;
        while (x % p == 0) x /= p, ++e;
        s[p] = e;
    }

    cin >> x;
    for (int p : primes) {
        int e = 0;
        while (x % p == 0) x /= p, ++e;
        if (e < s[p]) {
            sS[p] = s[p];
            s[p] = e;
        } else {
            sS[p] = e;
        }
    }

    for (int i = 1; i < n; ++i) {
        cin >> x;
        while (x > 1) {
            int p = lPF[x], e = 0;
            while (x % p == 0) x /= p, ++e;
            if (e < s[p]) {
                sS[p] = s[p];
                s[p] = e;
            } else if (e < sS[p]) {
                sS[p] = e;
            }
        }
    }

    ll ans = 1;
    for (int i = 1; i <= N; ++i) {
        if (sS[i]) {
            cerr << i << ' ' << s[i] << ' ' << sS[i] << '\n';
        }
        for (int k = 1; k <= sS[i]; ++k) {
            ans *= i;
        }
    }

    cout << ans << '\n';

    return 0;
}
