#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n; n /= 2;
    int a[n];
    for (int &i: a) cin >> i;

    int ans[2*n];
    for (int i = 0; i < n; i++)
        ans[2*i] = a[i];
    
    int fromStart = 0;
    int 
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

