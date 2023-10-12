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

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (auto x: a) {
        while (x != 1) {
            cnt[lPF[x]]++;
            x /= lPF[x];
        }
    }

    for (auto [x, f]: cnt) {
        if (f % n) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    seive();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
