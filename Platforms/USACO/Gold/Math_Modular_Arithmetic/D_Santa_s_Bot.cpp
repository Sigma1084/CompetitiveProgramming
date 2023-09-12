#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;

class Z {
    int val = 0;
    void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> k(n);
    vector<vector<int>> a(n);

    constexpr int N = 1000001;
    array<int, N> f;  // Frequency of each number
    f.fill(0);

    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j];
            f[a[i][j]]++;
        }
    }

    vector<Z> p(n);  // probability of winning if i-th child is chosen

    for (int i = 0; i < n; i++) {
        Z d = 0;
        for (int j = 0; j < k[i]; j++) {
            // Choosing the i-th kid and j-th gift
            p[i] += f[a[i][j]];  // Chance of winning
            d += n;  // Can chose any child
        }
        assert(d() != 0);
        p[i] /= d;
    }

    Z ans = std::accumulate(p.begin(), p.end(), Z(0)) / n;
    cout << ans << '\n';

    return 0;
}
