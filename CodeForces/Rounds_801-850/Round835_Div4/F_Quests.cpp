#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;


ll n, c, d;
vector<ll> a;
vector<ll> pref;


ll accumulated(ll k) {
	ll numInt = d/k;  // Length of these intervals = k
	ll rem = d%k;  // The remaining last interval
	return numInt * pref[min(n, k)] + pref[min(n, rem)];
}


void solve() {
	cin >> n >> c >> d;

	a.resize(n); for (ll &i: a) cin >> i;
	sort(a.begin(), a.end(), greater<int>());
	
	pref.resize(n+1);
	for (int i = 0; i < n; i++)
		pref[i+1] = pref[i] + a[i];

	// Impossible if a_max * d < c
	if (a.front()*d < c) {
		cout << "Impossible";
		return;
	}

	// Infinity if something contributed can finish off
	if (pref[min(n, d)] >= c) {
		cout << "Infinity";
		return;
	}

	// Can always be done in l, so move it furthur
	ll l = 1, r = d, acum;
	while (l <= r) {
		ll k = (l+r) / 2;
		acum = accumulated(k);
		if (acum >= c) {
			l = k+1;
		} else {
			r = k-1;
		}
	}
	cout << r-1;
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

