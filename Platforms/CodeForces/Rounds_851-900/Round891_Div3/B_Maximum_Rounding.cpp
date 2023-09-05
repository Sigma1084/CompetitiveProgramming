#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string ss; cin >> ss;
	ss = '0' + ss;
	int n = ss.size();

	string s = ss;
	int iAns = n;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] >= '5') {
			while (s[i - 1] == '9') {
				s[i - 1] = '0';
				i--;
			}
			s[i - 1] += 1;
			iAns = i;
		}
	}

	s = ss;
	for (int i = n - 1; i >= iAns; i--) {
		if (s[i] >= '5') {
			s[i] = '0';
			while (s[i - 1] == '9') {
				s[i - 1] = '0';
				i--;
			}
			s[i - 1] += 1;
		} else {
			s[i] = '0';
		}
	}

	if (s[0] == '0') {
		s = s.substr(1);
	}

	cout << s;
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
