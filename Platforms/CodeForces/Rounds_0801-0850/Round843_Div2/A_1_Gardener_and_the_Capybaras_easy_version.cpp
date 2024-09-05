#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	string s; cin >> s;
	int n = s.size();

	int a = -1;
	for (int i = 1; i+1 < n; i++)
		if (s[i] == 'a')
			a = i;
	
	if (a != -1) {
		cout << s.substr(0, a) << " a " << s.substr(a + 1);
	} else {
		// a bbbbb a or a bbbbb b or b bbbbb b
		cout << s.front() << ' ' << s.substr(1, n - 2) << ' ' << s.back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
