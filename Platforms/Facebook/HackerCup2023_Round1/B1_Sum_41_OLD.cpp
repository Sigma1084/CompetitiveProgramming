#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// constexpr int N = 3'188'646;
constexpr int N = 100;
constexpr int M = 41;

// posSum[n][k] := Can n be written as a sum to k
array<bitset<M>, N + 1> posSum;

void preCompute() {
    posSum.fill(bitset<M>());
    posSum[1][0] = true;  // 0 non-1 integers

    for (int n = 2; n <= 41; ++n) {
        posSum[n][n] = true;
    }

    for (int n = 2; n <= N; ++n) {
        for (int k = 0; k <= M; ++k) {
            for (int d = 2; d <= k; ++d) {
                cerr << "n = " << n << ", k = " << k << ", d = " << d << '\n';
                if (n % d) continue;  // Ensure d | n
                // Try to achieve n using d
                if (posSum[n/d][k-d])
                cerr << "Setting posSum[" << n << "][" << k << "] to posSum[" 
                     << n/d << "][" << k-d << "]\n";
                posSum[n][k] = posSum[n][k] | posSum[n/d][k-d];
            }
        }
    }
}

void solve() {
    int n; cin >> n;

    cout << posSum[n].to_string() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string file_name = "sum_41_chapter_1_validation";

    // freopen((file_name + "_input.txt").c_str(), "r", stdin);
    // freopen((file_name + "_output.txt").c_str(), "w", stdout);

    int t = 1;
    cin >> t;

    preCompute();

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

