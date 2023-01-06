#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int t = 0;
    if (s[0] == 'Y') {
        t = 0;
    } else if (s[0] == 'e') {
        t = 1;
    } else if (s[0] == 's') {
        t = 2;
    } else {
        cout << "NO";
        return;
    }

    string ss = "Yes";
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ss[(i+t)%3])
            ok = false;
    }

    cout << (ok ? "YES" : "NO");
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

