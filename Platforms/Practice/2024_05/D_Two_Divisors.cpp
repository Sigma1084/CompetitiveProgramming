#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<unsigned int N>
class Sieve {
    std::array<int, N + 1> _lPF;  // Least Prime Factor
    std::vector<int> primes;

    constexpr void sieve() noexcept {
        std::iota(_lPF.begin(), _lPF.end(), 0);
        _lPF[0] = _lPF[1] = -1;
        for (unsigned i = 2; i * i <= N; ++i) {
            if (_lPF[i] != i) continue;
            for (unsigned j = i * i; j <= N; j += i) {
                if (_lPF[j] == j) _lPF[j] = i;
            }
        }
        for (unsigned i = 2; i <= N; ++i) {
            if (_lPF[i] == i) {
                primes.push_back(i);
            }
        }
    }

public:
    [[nodiscard]] constexpr bool isPrime(int n) const {
        return _lPF[n] == n;
    }

    [[nodiscard]] constexpr int lPF(int n) const {
        return _lPF[n];
    }

    [[nodiscard]] constexpr std::vector<int> factors(int n) const {
        std::vector<int> factors;
        while (n != 1) {
            factors.push_back(_lPF[n]);
            n /= _lPF[n];
        }
        return factors;
    }

    Sieve() {
        sieve();
    }
};

constexpr int N = 1e7;
const Sieve<N + 1> S;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n), a(n), b(n);
    for (auto &x: v) {
        cin >> x;
    }

    for (int i = 0; i < n; ++i) {
        a[i] = 1;
        for (int x = v[i]; x > 1; ) {
            int p = S.lPF(x);
            a[i] *= p;
            while (x % p == 0) {
                x /= p;
            }
        }
        if (S.lPF(a[i]) == a[i]) {
            a[i] = -1;
            b[i] = -1;
        } else {
            b[i] = S.lPF(a[i]);
            a[i] /= b[i];
        }
    }

    for (auto x: a) {
        cout << x << ' ';
    }
    cout << '\n';
    for (auto x: b) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
