#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * A few ways to handle x
 * where x is required
 * Suppose x = 3
 * Then, receive 4 and send 1
 * 
 * Suppose x = 4
 * Then, either receive 4 OR receive 8 and send 4
 * 
 * Now, powers or 2 have 2 possibilities and the other numbers have 1
 * 
 * Suppose we have
 * pi = Number of 2^i to send => Receive 2^i and send 2^(i + 1)
 * ni = Number of 2^i to receive => Send 2^i and receive 2^(i + 1)
 * 
 * pi -= 1 => p(i+1) += 1 AND ni += 1
 * ni -= 1 => n(i+1) += 1 AND pi += 1
 * 
 * Come from beginning.
 * First balance them.
 */
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll avg = accumulate(a.begin(), a.end(), 0LL);
    if (avg % n) {
        cout << -1;
        return;
    }
    avg /= n;

    array<int, 32> cnt, pos, neg;
    cnt.fill(0); pos.fill(0); neg.fill(0);

    for (int ai: a) {
        int x = abs(ai - avg);
        if (x == 0) continue;

        if (x == (x & -x)) {
            if (ai > avg) {
                pos[__lg(x)]++;
            } else {
                neg[__lg(x)]++;
            }
        } else {
            int r = x & -x;
            x += r;
            if (x != (x & -x)) {
                cout << -1;
                return;
            }
            if (ai < avg) {
                swap(r, x);
            }
            cnt[__lg(r)]--;
            cnt[__lg(x)]++;            
        }
    }

    for (int i = 0; i <= 30; i++) {
        if (cnt[i] > 0) {
            if (neg[i] < cnt[i]) {
                cout << -1;
                return;
            }
            neg[i] -= cnt[i];
            neg[i + 1] += cnt[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
