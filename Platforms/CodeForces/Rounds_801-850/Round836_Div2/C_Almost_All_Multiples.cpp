#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    
    if (n % x) {
        cout << -1;
        return;
    }

    int a[n+1];
    for (int i = 2; i < n; i++)
        a[i] = i;
    a[1] = x; a[n] = 1;

    // Now factorize n/x
    int q = n / x;

    if (q != 1) {
        // Now factorize q and fill factors
        vector<int> facts;
        for (int i = 2; i*i <= q; i++) {
            while (q % i == 0) {
                facts.push_back(i);
                q /= i;
            }
        }

        if (q != 1) {
            facts.push_back(q);
        }

        int pos = x;
        for (auto &fact: facts) {
            a[pos] = pos * fact;
            pos *= fact;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
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

