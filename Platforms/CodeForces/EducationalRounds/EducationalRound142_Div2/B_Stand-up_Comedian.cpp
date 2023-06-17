#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int B, a, b, N; cin >> B >> a >> b >> N;
	if (a > b) swap(a, b);  // a <= b
	if (B == 0) {
		cout << 1;
		return;
	}

	int ans = min({B+a+b+N, 2*(B+a) + 1, 2*(B+b) + 1});

	// int ans = B + 2*a; b -= a;  // Tell one a and one b
	// // Now, both of them have mood = B
	// // We can finish b and then proceed to N

	// if (B < b) {
	// 	ans += B + 1;
	// } else {
	// 	B -= b;  // Alice lost b mood
	// 	ans += min(B+1, N);  // Alice can sit for at most B + 1
	// }

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
