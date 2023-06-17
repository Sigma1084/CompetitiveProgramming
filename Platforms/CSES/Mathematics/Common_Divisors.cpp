#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int max_ele = *max_element(a.begin(), a.end());
    vector<int> isPresent(max_ele + 1, 0);
    for (auto &i: a) {
        isPresent[i] += 1;
    }
    
    int ans = 1;
    for (int i = 2; i <= max_ele; i++) {
        // Now we need to check if there are 2 numbers that are divisible by i
        int counter = 0;
        for (int j = i; j <= max_ele and counter < 2; j += i) {
            counter += isPresent[j];
        }
        if (counter >= 2)
            ans = i;
    }

    cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

