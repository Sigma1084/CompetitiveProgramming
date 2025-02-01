/**
 * @file stringoholics.cpp
 */

#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1000000007;

constexpr int N = 1'000'000;
std::array<int, N + 1> lPF;
std::vector<int> primes;

constexpr bool isPrime(int n) {
    return lPF[n] == n;
}

void sieve() noexcept {
    std::iota(lPF.begin(), lPF.end(), 0);
    lPF[0] = lPF[1] = -1;
    for (int i = 2; i * i <= N; ++i) {
        if (lPF[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            if (lPF[j] == j) lPF[j] = i;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
}

/**
 * If we are rotating the string by one left or one right
 * We can improve this later
 */
int period1(const string &s) {
    int n = int(s.size());
    for (int d = 1; d < n; ++d) {
        if (n % d != 0) continue;
        // Here, d is a factor of n
        bool ok = true;
        for (int i = d; i < n; i += d) {
            if (s.substr(0, d) != s.substr(i, d)) {
                ok = false;
                break;
            }
        }
        // Least period
        if (ok) {
            return d;
        }
    }
    return n;
}

/**
 * If we are rotating the string i times in the i-th iteration
 * Choose the first n such that n * (n + 1) / 2 is a multiple of p1
 */
int period2(const string &s) {
    int p1 = period1(s);
    for (int n = 1; n <= p1; ++n) {
        if ((n * (n + 1) / 2) % p1 == 0) {
            return n;
        }
    }
    return p1 * (p1 + 1) / 2;
}

using ll = long long;

/**
 * Compute a^b mod P
 */
ll powMod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % P;
        }
        a = (a * a) % P;
        b /= 2;
    }
    return res;
}

/**
 * We need to compute the lcm of all period2s
 */
int solve(const vector<string> &A) {
    /**
     * For every prime p, we need to find the maximum power of p
     */
    map<int, int> maxPow;

    for (const string &s: A) {
        int per = period2(s);
        // Now this period is a multiple of some prime powers
        while (per > 1) {
            int p = lPF[per];
            int e = 0;
            while (per % p == 0) {
                per /= p;
                ++e;
            }
            // p^e is a factor of per
            maxPow[p] = max(maxPow[p], e);
        }
    }

    ll ans = 1;
    for (auto [p, e]: maxPow) {
        // p^e is a factor of the lcm
        ans = (ans * powMod(p, e)) % P;
    }

    return int(ans);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    sieve();

    vector<string> A = {"a", "aba", "ababa", "aba"};
    auto ans = solve(A);
    assert(ans == 4);

    return 0;
}
