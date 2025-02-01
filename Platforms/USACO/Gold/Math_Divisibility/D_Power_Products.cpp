#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <unsigned int N>
struct Sieve {
    using UInt = unsigned int;
    const std::array<UInt, N + 1> lPF = calclPF();
    const UInt P = numPrimes();
    const std::vector<UInt> primes = getPrimes();

    constexpr std::array<UInt, N + 1> calclPF() {
        std::array<UInt, N + 1> _lPF;
        std::iota(_lPF.begin(), _lPF.end(), 0);
        for (UInt i = 2; i * i <= N; ++i) {
            if (_lPF[i] != i) continue;
            for (UInt j = i * i; j <= N; j += i) {
                if (_lPF[j] == j) _lPF[j] = i;
            }
        }
        return _lPF;
    }

    constexpr UInt numPrimes() {
        UInt cnt = 0;
        for (UInt i = 2; i <= N; ++i) {
            if (lPF[i] == i) {
                ++cnt;
            }
        }
        return cnt;
    }

    constexpr auto getPrimes() {
        std::vector<UInt> primes(P);
        for (UInt i = 2, idx = 0; i <= N; ++i) {
            if (lPF[i] == i) {
                primes[idx++] = i;
            }
        }
        return primes;
    }

};

constexpr int N = 100000;
constexpr Sieve<N> S;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    cout << 1;

    return 0;
}
