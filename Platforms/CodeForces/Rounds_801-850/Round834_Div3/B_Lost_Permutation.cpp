#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int m, lostSum; cin >> m >> lostSum;
	vector<int> a(m); for (int &x: a) cin >> x;

    int n = *max_element(a.begin(), a.end());
    int totSum = n * (n + 1) / 2;
    int curSum = accumulate(a.begin(), a.end(), 0) + lostSum;

    // cout << n << ' ' << curSum << ' ' << totSum << '\n';
    for (n++ ; curSum > totSum; n++) {
        totSum += n;
    }

    if (curSum == totSum) {
        cout << "YES";
    } else {
        cout << "NO";
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

