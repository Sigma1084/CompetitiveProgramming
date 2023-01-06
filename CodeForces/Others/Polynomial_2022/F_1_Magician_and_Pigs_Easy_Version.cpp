#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 998244353;

template <unsigned int P = MOD>
struct MI {
    using ll = long long int;
    ll x = 0;
    MI() = default;
    MI(const ll &v): x((P + v%P) % P) {}
    MI(const int &v): MI<P>((ll) v) {}
    void normalize() { if (x < 0) x += P; if (x > P) x -= P; }
    MI<P> operator - () const { return MI<P>(-x); }
    MI<P> operator ++ (int) { return operator+=(1); }
    MI<P> operator -- (int) { return operator-=(1); }
    MI<P>& operator += (const MI<P> &a) { x += a.x; normalize(); return *this; }
    MI<P>& operator -= (const MI<P> &a) { x -= a.x; normalize(); return *this; }
    MI<P>& operator *= (const MI<P> &a) { (x *= a.x) %= P; return *this; }
    MI<P> inv() const { return _pow(*this, P-2); }
    MI<P>& operator /= (const MI<P> &a) { x *= a.inv().x; return *this; }
    bool operator == (const MI<P> &a) { return x == a.x; }
    bool operator != (const MI<P> &a) { return x != a.x; }
    friend MI<P> operator + (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans += b; }
    friend MI<P> operator - (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans -= b; }
    friend MI<P> operator * (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans *= b; }
    friend MI<P> operator / (const MI<P> &a, const MI<P> &b) { MI<P> ans = a; return ans /= b; }
    friend std::ostream& operator << (std::ostream &o, const MI<P> &m) { return o << m.x; }
    friend std::istream& operator >> (std::istream &i, MI<P> &m) { return i >> m.x; }
};
typedef MI<> Z;

template<class Map, class Merger>
void merge(Map& dest, const Map& source, Merger merger)
{
    auto it1 = dest.begin();
    auto it2 = source.begin();
    auto&& comp = dest.value_comp();

    for (; it1 != dest.end() && it2 != source.end(); ) {
        if (comp(*it1, *it2)) {
            ++it1;
        } else if (comp(*it2, *it1)) {
            dest.insert(it1, *it2); // with hint to have correct complexity
            ++it2;
        } else { // equivalent
            it1->second = merger(it1->second, it2->second);
            ++it1;
            ++it2;
        }
    }
    dest.insert(it2, source.end());
}


void solve() {
	int n; cin >> n;
    int t, x;

	map<int, Z> m;
    Z min;
    ll bal = 0, tot = 0;

    auto clearBalance = [&] () {
        if (bal == 0) return;
        m.erase(m.begin(), m.upper_bound(bal));
        auto oM = m;
        m.clear();
        for (auto it = oM.begin(); it != oM.end(); it++) {
            m[it->first - bal] = it->second;
        }
        bal = 0;
    };

    for (int _ = 0; _ < n; _++) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            clearBalance();
            m[x] += 1;
        }

        if (t == 2) {
            cin >> x;
            if(x == 0) continue;
            bal += x; tot += x;
        }

        if (t == 3) {
            clearBalance();
            auto cur = m;
            bal = tot; tot *= 2;
            clearBalance();
            merge(m, cur, [] (const Z &z1, const Z &z2) { return z1 + z2; } );
        }
    }

    clearBalance();
    Z ans = 0;
    for (auto &[hp, f]: m)
        ans += f;
    
    cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

