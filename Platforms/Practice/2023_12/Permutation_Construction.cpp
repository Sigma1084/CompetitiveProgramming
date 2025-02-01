#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    --x;  // Use 0-indexing

    // Ans
    vector<int> a(n);

    if (n % 2 == 0) {
        // Even case

        // Example when n = 6, x = 1 (0-indexing)
        // Required: [1 3 5 0 2 4]

        // Fill the first half with numbers of same parity
        a[0] = x;
        for (int i = 1; i < n / 2; ++i) {
            a[i] = (a[i-1] + 2) % n;
        }
        // a = [1 3 5 _ _ _]

        // Fill the other half with complements
        for (int i = n / 2, j = i - 1; i < n; ++i, --j) {
            a[i] = n - 1 - a[j];
        }
        // a = [1 3 5 0 2 4]
    } else {
        // Odd case

        // Impossible case
        if (x + 1 == (n + 1) / 2) {
            cout << -1;
            return;
        }

        bool rev = 2*x > n;
        if (rev) {
            // [5, 0] => [5, 4] (0-indexing)
            x = n - 1 - x;
        }

        // Example when n = 7, x = 1 (0-indexing)
        // Required: [1 2 0 3 6 4 5]

        int k = (n - 1) / 2;
        a[0] = x;
        for (int i = 1; i < k; ++i) {
            a[i] = (a[i-1] + 1) % k;
        }
        // a = [1 2 0 _ _ _ _]

        a[k] = k;
        for (int i = k + 1, j = k - 1; i < n; ++i, --j) {
            a[i] = n - 1 - a[j];
        }
        // a = [1 2 0 3 6 4 5]
        
        if (rev) {
            reverse(a.begin(), a.end());
        }
    }

    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        b[i] = a[i] - a[i+1];
    }
    for (int i = 0, j = n - 2; i < j; ++i, --j) {
        assert(b[i] == b[j]);
    }

    // Print in 1-indexing
    for (auto x: a) {
        cout << x + 1 << ' ';
    }
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
