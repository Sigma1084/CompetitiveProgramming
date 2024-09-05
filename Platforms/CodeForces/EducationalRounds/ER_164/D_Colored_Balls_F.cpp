#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

class Z {
    int val = 0;
    constexpr void normalize() {
        if (val < 0) val += P; if (val >= P) val -= P;
    }
public:
    Z() = default;
    template<class T> constexpr Z(const T &v): val((P + v%P) % P) {}
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


template <typename T>
class SegTree {
    int n;
    std::vector<T> s;

public:
    static constexpr T ID = 0;
    static T f(T a, T b) { return a + b; }

    SegTree(unsigned _n): n(1 << __lg(2*_n - 1)), s(2*n, ID) {}

    template <typename U>
    SegTree(const std::vector<U> &a): SegTree(a.size()) {
        std::copy(a.begin(), a.end(), s.begin() + n);
        for (auto i = n - 1; i > 0; --i)
            s[i] = f(s[i*2], s[i*2 + 1]);
    }

    void update(unsigned idx, T val) {
        for (s[idx += n] += val; idx /= 2; )
            s[idx] = f(s[idx*2], s[idx*2 + 1]);
    }

    T query(unsigned l, unsigned r) {
        assert(l <= r);
        T rL = ID, rR = ID;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) rL = f(rL, s[l++]);
            if (r % 2 == 0) rR = f(s[r--], rR);
        }
        return f(rL, rR);
    }

    T operator[](unsigned idx) {
        assert(idx < n);
        return s[idx + n];
    }

    friend ostream& operator << (ostream &os, SegTree st) {
        os << '[';
        for (int i = 0; i < st.n; ++i) {
            os << st[i];
            if (i < st.n - 1) os << ' ';
        }
        return os << ']';
    }
};

constexpr int A = 5;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    /**
     * nO[i] := Number of subsets with sum = i and i odd
     */

    SegTree<Z> s(A + 1);
    SegTree<int> nO(A + 1), nE(A + 1);

    nE.update(0, 1);
    s.update(0, 0);

    Z ans = 0;
    for (int i = 0; i < n; ++i) {
        // When a[i] is the greatest element
        ans += Z(a[i]) * (nO.query(0, a[i] - 1) + nE.query(0, a[i] - 1));
        ans += (s.query(a[i], A) + Z(a[i]) 
            * (nO.query(a[i], A) + nE.query(a[i], A))) / 2;

        if (a[i] % 2 == 1) {
            ans += nE.query(a[i], A) / 2;
        } else {
            ans += nO.query(a[i], A) / 2;
        }

        // Updating the thing
        for (int j = A; j >= 0; --j) {
            s.update(min(A, j + a[i]), (Z(a[i]) + j) * (nE[j] + nO[j]));
            if (a[i] % 2 == 0) {
                nE.update(min(A, j + a[i]), nE[j]);
                nO.update(min(A, j + a[i]), nO[j]);
            } else {
                nE.update(min(A, j + a[i]), nO[j]);
                nO.update(min(A, j + a[i]), nE[j]);
            }
        }

        // cerr << ans << '\n';
        // cerr << "Odd: ";
        // cerr << nO << '\n';
        // cerr << "Even: ";
        // cerr << nE << '\n';
        // cerr << "Sum: ";
        // cerr << s << '\n';
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
