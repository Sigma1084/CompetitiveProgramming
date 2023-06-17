#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

bool isPalindrome(const string &s) {
	int n = s.size();
	for (int i = 0, j = n - 1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = n + 1;

	for (int i = 0; i < 26; i++) {
		char cur = 'a' + i;

		string t;
		for (char c: s) {
			if (c != cur)
				t.push_back(c);
		}

		// If it is not a palindrome it can never be a palindrome
		if (!isPalindrome(t)) continue;

		// Now maybe we can leave some and still manage to obtain a palindrome
		int rem = 0;
		for (int i = 0, j = n - 1; i < j; ) {
			if (s[i] == s[j]) i++, j--;
			else if (s[i] == cur) i++, rem++;
			else if (s[j] == cur) j--, rem++;
			else assert(false);
		}

		ans = min(rem, ans);
	}

	if (ans == n + 1) ans = -1;

	cout << ans;
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
