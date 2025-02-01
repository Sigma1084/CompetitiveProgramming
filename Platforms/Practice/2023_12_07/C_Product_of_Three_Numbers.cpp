#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 40000;
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

void solve() {
    int n;
    cin >> n;

    vector<int> ps;
    for (int p: primes) {
        if (n % p == 0) {
            ps.push_back(p);
            n /= p;
        }
        if (ps.size() == 2) {
            break;
        }
    }

    if (ps.size() == 2) {
        if (n != ps[0] and n != ps[1] and n != 1) {
            cout << "YES\n";
            cout << ps[0] << ' ' << ps[1] << ' ' << n;
        } else {
            cout << "NO";
        }
    } else if (ps.size() == 1) {
        // We have only 1 prime
        int p = ps[0];
        if (n % (p * p)) {
            cout << "NO";
            return;
        }
        ps.push_back(p * p);
        n /= ps[1];
        if (n != 1 and ps[0] != ps[1] and ps[1] != n and n != ps[0]) {
            cout << "YES\n";
            cout << ps[0] << ' ' << ps[1] << ' ' << n;
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
