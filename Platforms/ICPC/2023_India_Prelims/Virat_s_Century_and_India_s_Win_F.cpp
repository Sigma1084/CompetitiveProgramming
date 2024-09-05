#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1000000007;

class Z {
    int val = 0;
    void normalize() { if (val < 0) val += P; if (val >= P) val -= P; }
public:
    Z() = default;
    template<class T> Z(const T &v): val((P + v%P) % P) {}
    Z(const Z &z) = default;
    Z operator - () const { return Z(0) -= val; }
    constexpr int operator ()() const { return val; }
    Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    Z inv() const { return pow(P - 2); }
    Z& operator += (Z a) { val += a.val; normalize(); return *this; }
    Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
    Z& operator *= (Z a) { val = 1LL * val * a.val % P; return *this; }
    Z& operator /= (Z a) { return *this *= a.inv(); }
    Z& operator ++ (int) { return operator+=(1); }
    Z& operator -- (int) { return operator-=(1); }
    Z operator + (Z a) { return Z(*this) += a; }
    Z operator - (Z a) { return Z(*this) -= a; }
    Z operator * (Z a) { return Z(*this) *= a; }
    Z operator / (Z a) { return Z(*this) /= a; }
    constexpr bool operator == (Z a) const { return val == a.val; }
    constexpr bool operator != (Z a) const { return val != a.val; }
    friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};

bool isDone[152][62][12][152][2][2];
Z dp[152][62][12][152][2][2];

const Z by6 = Z(1) / Z(6);

Z f(int n, int b, int w, int v, int s, int viratAlive) {
    if (w <= 0) {
        return 0;
    }

    if (b <= 0) {
        if (n <= 0 and v >= 100) {
            return 1;
        } else {
            return 0;
        }
    }

    if (n <= 0) {
        return v >= 100;
    }

    if (isDone[n][b][w][v][s][viratAlive]) {
        return dp[n][b][w][v][s][viratAlive];
    }

    Z &ans = dp[n][b][w][v][s][viratAlive];
    ans = 0;

    if(viratAlive == 1) {
        if(s == 1) {
            Z wicketFalls, run1Score, run3Score, run2Score, run4Score, run6Score;
            if((b-1) % 6 == 0) {
                wicketFalls = f(n, b-1, w-1, v, 0, 0) * by6;
                run1Score = f(n-1, b-1, w, v+1, 1, 1) * by6;
                run2Score = f(n-2, b-1, w, v+2, 0, 1) * by6;
                run3Score = f(n-3, b-1, w, v+3, 1, 1) * by6;
                run4Score = f(n-4, b-1, w, v+4, 0, 1) * by6;
                run6Score = f(n-6, b-1, w, v+6, 0, 1) * by6;
            } else {
                wicketFalls = f(n, b-1, w-1, v, 0, 0) * by6;
                run1Score = f(n-1, b-1, w, v+1, 0, 1) * by6;
                run2Score = f(n-2, b-1, w, v+2, 1, 1) * by6;
                run3Score = f(n-3, b-1, w, v+3, 0, 1) * by6;
                run4Score = f(n-4, b-1, w, v+4, 1, 1) * by6;
                run6Score = f(n-6, b-1, w, v+6, 1, 1) * by6;
            }
            ans += run1Score;
            ans += run3Score;
            ans += run2Score;
            ans += run4Score;
            ans += run6Score;
            ans += wicketFalls;
        } else {
            Z wicketFalls,run1Score, run3Score, run2Score, run4Score, run6Score;
            if((b-1) % 6 == 0) {
                wicketFalls = f(n, b-1, w-1, v, 1, 1) * by6;
                run1Score = f(n-1, b-1, w, v, 0, 1) * by6;
                run2Score = f(n-2, b-1, w, v, 1, 1) * by6;
                run3Score = f(n-3, b-1, w, v, 0, 1) * by6;
                run4Score = f(n-4, b-1, w, v, 1, 1) * by6;
                run6Score = f(n-6, b-1, w, v, 1, 1) * by6;
            } else {
                wicketFalls = f(n, b-1, w-1, v, 0, 1) * by6;
                run1Score = f(n-1, b-1, w, v, 1, 1) * by6;
                run2Score = f(n-2, b-1, w, v, 0, 1) * by6;
                run3Score = f(n-3, b-1, w, v, 1, 1) * by6;
                run4Score = f(n-4, b-1, w, v, 0, 1) * by6;
                run6Score = f(n-6, b-1, w, v, 0, 1) * by6;
            }
            ans += run1Score;
            ans += run3Score;
            ans += run2Score;
            ans += run4Score;
            ans += run6Score;
            ans += wicketFalls;
        }
    } else {
        if (v < 100) {
            return 0;
        }
        ans += f(n, b-1, w-1, v, 0, 0) * by6;
        ans += f(n-1, b-1, w, v, 0, 0) * by6;
        ans += f(n-3, b-1, w, v, 0, 0) * by6;
        ans += f(n-2, b-1, w, v, 0, 0) * by6;
        ans += f(n-4, b-1, w, v, 0, 0) * by6;
        ans += f(n-6, b-1, w, v, 0, 0) * by6;
    }

    isDone[n][b][w][v][s][viratAlive] = true;
    cerr << "dp[" << n << "][" << b << "][" << w << "][" << v << "][" << s << "][" << viratAlive << "] = " << ans << '\n';
    return ans;
}

void solve() {
    int n, b, w, x;
    cin >> n >> b >> w >> x;
    Z ans = f(n, b, 10-w, x, 1, 1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(isDone, false, sizeof(isDone));

    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}