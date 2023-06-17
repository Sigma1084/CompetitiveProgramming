#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const int N = 26;

void solve() {
	int n; cin >> n;
    string s; cin >> s;

    // There are n - 1 pairs
    // If any pair repeats then done

    int f[N][N] = {0};
    for (int i = 0; i+1 < n; i++) {
        int a = s[i] - 'a', b = s[i+1] - 'a';
        if (a != b) {
            if (f[a][b]) {
                cout << "YES";
                return;
            }
        } else {
            if (f[a][a] > 1) {
                cout << "YES";
                return;
            } else if (f[a][a] and s[i-1] != s[i]) {
                cout << "YES";
                return;
            }
        }
        f[a][b]++;
    }

    cout << "NO";
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

