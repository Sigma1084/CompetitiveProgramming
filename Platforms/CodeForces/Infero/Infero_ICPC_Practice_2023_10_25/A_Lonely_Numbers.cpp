#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    array<int, N + 1> ans;
    ans.fill(0);
    ans[1] = 1;
    for (int p: primes) {
        ans[p] = 1;
        if (1LL * p * p <= N) {
            ans[p * p] = -1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        ans[i] += ans[i - 1];
    }

    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}
