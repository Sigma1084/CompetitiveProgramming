#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<pair<int, char>> f(26);
	for (int i = 0; i < 26; i++) f[i].second = i + 'a';
	for (char &c: s) f[c - 'a'].first++;
	sort(all(f)); reverse(all(f));

	int ans = INT_MAX, ansNum;
	for (int i = 26; i >= 1; i--) {
		// We can make it exactly equal to i many characters
		if (n % i) continue;
		int req = n / i;

		int curr = 0;
		for (int j = 0; j < i; j++) {
			curr += max(f[j].first - req, 0);
		}
		for (int j = i; j < 26; j++) {
			curr += f[j].first;
		}
		if (curr < ans) {
			ans = curr;
			ansNum = i;
		}
	}

	int req = n / ansNum;

	vector<bool> sp(26);
	for (int i = 0; i < ansNum; i++) sp[f[i].second - 'a'] = true;

	vector<int> chInd(26);
	for (int i = 0; i < 26; i++) chInd[f[i].second - 'a'] = i;
	
	int chChr = ansNum-1;

	cout << ans << '\n';
	for (char &c: s) {
		if (sp[c - 'a']) {
			if (f[chInd[c-'a']].first <= req) {
				cout << c;
			} else {
				// Replace this character with shit
				while (f[chChr].first >= req) chChr--;
				cout << f[chChr].second;
				f[chChr].first++;
				f[chInd[c-'a']].first--;  // So that it gets printed later
			}
		} else {
			while (f[chChr].first >= req) chChr--;
			f[chChr].first++;
			cout << f[chChr].second;
		}
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
