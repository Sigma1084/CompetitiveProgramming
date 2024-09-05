#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define F first;
#define S second;

const int P = 1000000007;

class Z {
	int val = 0;
	void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
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
	Z inv() const { return pow(P - 2); }
	Z& operator += (Z a) { val += a.val; normalize(); return *this; }
	Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
	Z& operator *= (Z a) { val = (int64_t) val * a.val % P; return *this; }
	Z& operator /= (Z a) { return *this *= a.inv(); }
	Z& operator ++ (int) { return operator+=(1); }
	Z& operator -- (int) { return operator-=(1); }
	Z operator + (Z a) { return Z(*this) += a; }
	Z operator - (Z a) { return Z(*this) -= a; }
	Z operator * (Z a) { return Z(*this) *= a; }
	Z operator / (Z a) { return Z(*this) /= a; }
	bool operator == (Z a) const { return val == a.val; }
	bool operator != (Z a) const { return val != a.val; }
	bool operator < (Z a) const { return val < a.val; }
	bool operator > (Z a) const { return val > a.val; }
	friend std::ostream& operator << (std::ostream &o, Z m) { return o << m.val; }
	friend std::istream& operator >> (std::istream &i, Z m) { return i >> m.val; }
};

Z dp[152][62][12][152][2][2];

Z f(int n, int b, int w, int v, int s, int viratAlive)
{
    if(n <= 0){
        if(v >= 100) return 1;
        else return 0;
    }
    if(w <= 0 || b <= 0){
        return 0;
    }
    // if(dp[n][b][w][v][s][viratAlive] != -1){
    //     return dp[n][b][w][v][s][viratAlive];
    // }
    Z ans = 0;
    if(viratAlive == 1){
        if(s == 1){
            Z wicketFalls,run1Score, run3Score, run2Score, run4Score, run6Score;
            if((b-1) % 6 == 0){
                wicketFalls = f(n, b-1, w-1, v, 0, 0) / Z(6);
            } else {
                wicketFalls = f(n, b-1, w-1, v, 0, 0) / Z(6);
            }
            if((b-1) % 6 == 0){
                run1Score = f(n-1, b-1, w, v+1, 1, 1) / Z(6);
            } else {
                run1Score = f(n-1, b-1, w, v+1, 0, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run3Score = f(n-3, b-1, w, v+3, 1, 1) / Z(6);
            } else {
                run3Score = f(n-3, b-1, w, v+3, 0, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run2Score = f(n-2, b-1, w, v+2, 0, 1) / Z(6);
            } else {
                run2Score = f(n-2, b-1, w, v+2, 1, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run4Score = f(n-4, b-1, w, v+4, 0, 1) / Z(6);
            } else {
                run4Score = f(n-4, b-1, w, v+4, 1, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run6Score = f(n-6, b-1, w, v+6, 0, 1) / Z(6);
            } else {
                run6Score = f(n-6, b-1, w, v+6, 1, 1) / Z(6);
            }
            ans += run1Score;
            ans += run3Score;
            ans += run2Score;
            ans += run4Score;
            ans += run6Score;
            ans += wicketFalls;
        } else {
            Z wicketFalls,run1Score, run3Score, run2Score, run4Score, run6Score;
            if((b-1) % 6 == 0){
                wicketFalls = f(n, b-1, w-1, v, 1, 1) / Z(6);
            } else {
                wicketFalls = f(n, b-1, w-1, v, 0, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run1Score = f(n-1, b-1, w, v, 0, 1) / Z(6);
            } else {
                run1Score = f(n-1, b-1, w, v, 1, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run3Score = f(n-3, b-1, w, v, 0, 1) / Z(6);
            } else {
                run3Score = f(n-3, b-1, w, v, 1, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run2Score = f(n-2, b-1, w, v, 1, 1) / Z(6);
            } else {
                run2Score = f(n-2, b-1, w, v, 0, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run4Score = f(n-4, b-1, w, v, 1, 1) / Z(6);
            } else {
                run4Score = f(n-4, b-1, w, v, 0, 1) / Z(6);
            }
            if((b-1) % 6 == 0){
                run6Score = f(n-6, b-1, w, v, 1, 1) / Z(6);
            } else {
                run6Score = f(n-6, b-1, w, v, 0, 1) / Z(6);
            }
            ans += run1Score;
            ans += run3Score;
            ans += run2Score;
            ans += run4Score;
            ans += run6Score;
            ans += wicketFalls;
        }
    } else {
        Z wicketFalls = f(n, b-1, w-1, v, 0, 0) / Z(6);
        Z run1Score, run3Score, run2Score, run4Score, run6Score;
        run1Score = f(n-1, b-1, w, v, 0, 0) / Z(6);
        run3Score = f(n-3, b-1, w, v, 0, 0) / Z(6);
        run2Score = f(n-2, b-1, w, v, 0, 0) / Z(6);
        run4Score = f(n-4, b-1, w, v, 0, 0) / Z(6);
        run6Score = f(n-6, b-1, w, v, 0, 0) / Z(6);
        ans += run1Score;
        ans += run3Score;
        ans += run2Score;
        ans += run4Score;
        ans += run6Score;
        ans += wicketFalls;
    }
    return ans;
    // return dp[n][b][w][v][s][viratAlive] = ans;
}

void solve()
{
    int n,b,w,x;
    cin >> n >> b >> w >> x;
    Z ans = f(n, b, 10-w, x, 1, 1);
    cout << ans;
    // cout << dp[n][b][10-w][x][1][1];
}

void precompute()
{
    // int n=150,b=60,w=0,x=0;
    // Z ans = f(n, b, 10-w, x, 1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    // precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}
