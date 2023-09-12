#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6;

std::vector<bool> isPrime(N + 1);
std::vector<int> primes;
std::vector<int> lPF(N + 1);  // Least Prime Factor

void seive() {
    isPrime.assign(N + 1, true);
    std::iota(lPF.begin(), lPF.end(), 0);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
            if (lPF[j] == j) lPF[j] = i;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    seive();

    ll n, k;
    cin >> n >> k;

    k = (k + 1) / 2;
    for (; k and n != 1; k--) {
        ll phi = n;
        // All the primes we encounter
        for (int p: primes) {
            if (n % p) continue;
            if (p > n) break;
            phi = phi / p * (p - 1);
            while (n % p == 0) n /= p;
        }
        if (n > 1) phi = phi / n * (n - 1);
        n = phi;
    }

    cout << n % 1000000007 << '\n';

    return 0;
}
