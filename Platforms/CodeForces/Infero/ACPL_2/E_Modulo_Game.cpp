#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1000000;
std::array<int, N + 1> lPF;
std::bitset<N + 1> isPrime;
std::vector<int> primes;

constexpr void seive() noexcept {
    std::iota(lPF.begin(), lPF.end(), 0);
    for (int i = 2; i * i <= N; ++i) {
        if (lPF[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            if (lPF[j] == j) lPF[j] = i;
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (lPF[i] == i) {
            isPrime.set(i, true);
            primes.push_back(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    seive();

    int n, k;
    cin >> n >> k;
    
    map<int, pair<int, bool>> mp;
    for (int m = k; m > 1; ) {
        int p = lPF[m], e = 0;
        while (m % p == 0) {
            m /= p;
            e++;
        }
        mp[p] = {e, false};
    }

    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        while (h > 1) {
            int p = lPF[h], e = 0;
            while (h % p == 0) {
                h /= p;
                e++;
            }
            if (mp.find(p) == mp.end()) continue;
            if (mp[p].first <= e) {
                mp[p].second = true;
            }
        }
    }

    for (auto [p, ep]: mp) {
        if (!ep.second) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
