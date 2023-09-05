#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	string s = "CIPHER";
	for (int i = 0; i < 26; i++) {
		string t = s;
		for (char &c: t) {
			c = ((c - 'A') + i) % 26 + 'A';
		}
		cout << i << ": " << t << '\n';
	}

	return 0;
}
