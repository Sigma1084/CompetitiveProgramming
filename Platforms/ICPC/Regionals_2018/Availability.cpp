#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }


constexpr int P = 7;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val >= P) val -= P; }
public:
	Z() = default;
	template<class T> Z(const T &v): val((P + v%P) % P) {}
	Z(const Z &z) = default;
	Z operator - () const { return Z(0) -= val; }
	int operator ()() const { return val; }
	Z pow(int64_t b) const {
		assert(b >= 0); Z ans = 1;
		for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
		return ans;
	}
	Z inv() const { return pow(P-2); }
	Z& operator += (const Z &a) { val += a.val; normalize(); return *this; }
	Z& operator -= (const Z &a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (const Z &a) { val = (int64_t) val * a.val % P; return *this; }
	Z& operator /= (const Z &a) { *this *= a.inv(); return *this; }
	friend Z operator + (const Z &a, const Z &b) { return Z(a) += b; }
	friend Z operator - (const Z &a, const Z &b) { return Z(a) -= b; }
	friend Z operator * (const Z &a, const Z &b) { return Z(a) *= b; }
	friend Z operator / (const Z &a, const Z &b) { return Z(a) /= b; }
	bool operator == (const Z &a) const { return val == a.val; }
	bool operator != (const Z &a) const { return val != a.val; }
	bool operator < (const Z &a) const { return val < a.val; }
	bool operator > (const Z &a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, const Z &m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z &m) { return i >> m.val; }
};

int conv(string s)
{
	int h = stoi(s.substr(0,2));
	int m = stoi(s.substr(3,2));
	int val = (h*60)+m;
	return val;
}

string conv2(int val)
{
	int h = val/60;
	int m = val % 60;
	string ans = "";
	if(h < 10){
		ans += "0" + to_string(h);
	} else {
		ans += to_string(h);
	}
	ans += ":";

	if(m < 10){
		ans += "0" + to_string(m);
	} else {
		ans += to_string(m);
	}
	return ans;
}

void solve() {
	int t; cin >> t;
	t *= 60;
	vector<pair<int,int>> ans[7];

	vector<pair<int,int>> a[7];
	for(int i = 0; i < 7; i++){
		int k; cin >> k;
		for(int j = 0; j < k; j++){
			string s,t; cin >> s >> t;
			int s1 = conv(s);
			int s2 = conv(t);
			a[i].emplace_back(s1,s2);
		}
	}

	for(int i = 0; i < 7; i+=1){
		for(auto& it : a[i]){
			int c1 = it.first - t;
			int c2 = it.second - t;
			// cerr << c1 << ' ' << c2 << "\n";
			if(c1 >= 0){
				c2 = (c2 < 0) ? c2+1440 : c2;
				ans[i].emplace_back(c1,c2);
			} else {
				int ind = (i+6)%7;
				if(c2 < 0){
					ans[ind].emplace_back(c1+1440, c2+1440);
				} else {
					ans[ind].emplace_back(c1+1440, 0);
					ans[i].emplace_back(0,c2);
				}
			}
		}
	}

	vector<pair<int,int>> ans2[7];
	for(int i = 0; i < 7; i++){
		if((int)ans[i].size() == 0) continue;
		sort(ans[i].begin(), ans[i].end());
		int l = ans[i][0].first;
		int r = ans[i][0].second;
		for(int j = 1; j < (int)ans[i].size(); j++){
			if(r < ans[i][j].first){
				ans2[i].emplace_back(l,r);
				l = ans[i][j].first;
				r = ans[i][j].second;
			} else {
				r = max(r, ans[i][j].second);
			}
		}
		ans2[i].emplace_back(l,r);
	}


	for(int i = 0; i < 7; i++){
		cout << ans2[i].size() << "\n";
		for(auto& it : ans2[i]){
			string s = conv2(it.first);
			string t = conv2(it.second);
			cout << s << ' ' << t << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
