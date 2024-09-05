#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2097153;
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
    int n,k;
    cin >> n >> k;

    vector<int> a(k);
    for (auto &x: a) {
        cin >> x;
    }

    function<int(int)> dfs = [&](int n){
        if(n == 1) return 0;
    };
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
