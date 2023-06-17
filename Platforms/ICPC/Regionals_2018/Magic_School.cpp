#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	if(n == 1){
		cout << -1;
		return;
	}
	if(sum % (n-1) != 0){
		cout << -1;
		return;
	}
	int pass = sum/(n-1);
	int x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == pass - 1){
			x++;
		} else if (a[i] == pass){
			y++;
		} else {
			cout << -1;
			return;
		}
	}
	if(x == pass && y == n-pass){
		cout << n-pass;
	} else {
		cout << -1;
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
