#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<unsigned int N>
class Sieve {
    std::array<int, N + 1> _lPF;  // Least Prime Factor
    std::vector<int> _primes;

    constexpr void sieve() noexcept {
        std::iota(_lPF.begin(), _lPF.end(), 0);
        _lPF[0] = _lPF[1] = -1;
        for (unsigned int i = 2; i * i <= N; ++i) {
            if (_lPF[i] != i) continue;
            for (unsigned int j = i * i; j <= N; j += i) {
                if (_lPF[j] == j) _lPF[j] = i;
            }
        }
        for (unsigned int i = 2; i <= N; ++i) {
            if (_lPF[i] == i) {
                _primes.push_back(i);
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

    const std::vector<int> &primes = _primes;

    Sieve() {
        sieve();
    }
};

constexpr int N = 1e6;
const Sieve<N> s;

vector<int> odds, evens;

void preCompute() {
    odds.reserve(N);
    evens.reserve(N);
    vector<int> b;
    int cur;

    odds = {1, 1, 2, 2, 3, 3, 1};
    cur = 3;
    while (odds.size() < N) {
        b = {cur + 1, cur + 1, 2, cur + 2, cur + 2, 3, cur + 1};
        odds.insert(odds.end(), b.begin(), b.end());
        for (int i = 4; i <= cur; i += 2) {
            b = {i, cur + 2, i + 1, cur + 1};
            odds.insert(odds.end(), b.begin(), b.end());
        }
        odds.push_back(cur + 2);
        odds.push_back(1);
        cur += 2;
    }

    evens = {2, 2, 1, 1};
    cur = 2;
    while (evens.size() < N) {
        b = {cur + 1, cur + 1, 2, cur + 2, cur + 2};
        evens.insert(evens.end(), b.begin(), b.end());
        for (int i = 3; i <= cur; i += 2) {
            b = {i, cur + 1, i + 1, cur + 2};
            evens.insert(evens.end(), b.begin(), b.end());
        }
        evens.push_back(1);
        cur += 2;
    }

}

vector<int> o1, e1;

void solve() {
    int n;
    cin >> n;

    int o = *max_element(odds.begin(), odds.begin() + n);
    int e = *max_element(evens.begin(), evens.begin() + n);

    const vector<int> &v = (o <= e) ? odds : evens;

    for (int i = 0; i < n; ++i) {
        cout << s.primes[v[i] - 1] << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    preCompute();

    o1 = odds;
    e1 = evens;

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
