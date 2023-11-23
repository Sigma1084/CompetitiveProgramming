#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 4e6;

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

constexpr int N = 4e6;
void solve() {
    int n; cin >> n;

    bitset<N> s;
    cin >> s;

    int nQ; cin >> nQ;
    bitset<N> bro, ans;

    for (int x; nQ--; ) {
        cin >> x;
        bro[x] = bro[x] ^ 1;
    }

    for (int i = 1; i <= n; ++i) {
        ans[i] = s[i] ^ bro[i];
        if (ans[i] )
        if (bro[i-1]) {
            for (int j = i; j <= n; j += i) {
                ans[j-1] = ans[j-1] ^ 1;
            }
        }
    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    seive();

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

