#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int k, n;
    cin >> n >> k;

    /**
     * Let's say the sequence we have is of the form ak + b \n
     * Initially, a = 1 and b = 0 \n
     * If k < n/2, we can calculate the k-th element to be removed \n
     *   which is just 2k-th element and we're done \n
     * Othwise, update a, b, k, n and repeat the process \n
     * Update n to be the maximum value k can take
     */

    int a = 1, b = 0;
    while (2*k > n) {
        k -= n/2;

        if (a+b <= 0) {
            // First element is virtual
            if (n%2 == 0) {
                // Get rid of the virtual emenet
                n -= n/2;
                n--;
                b += a;
            } else {
                // We need a virtual element again
                n -= n/2;
                b += -a;
            }
        } else {
            // First element is real
            if (n%2 == 0) {
                // We don't need a virtual
                n -= n/2;
                b += -a;
            } else {
                // Introduce a virtual element
                n -= n/2;
                n++;
                b += -3*a;
            }
        }

        a *= 2;
    }
    cout << 2*a*k + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

