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

constexpr int A = 5000;

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
     * nE[i] := Number of subsets with sum = i and i even
     */
    vector<Z> s(A + 1);
    vector<Z> nO(A + 1), nE(A + 1);

    nE[0] = 1;
    s[0] = 1;

    Z ans = 0;
    for (int i = 0; i < n; ++i) {
        // When a[i] is the greatest element
        for (int j = 0; j < a[i]; ++j) {
            ans += Z(a[i]) * (nO[j] + nE[j]);
        }

        Z cur = 0;
        for (int j = a[i]; j <= A; ++j) {
            cur += s[j] + Z(a[i]) * (nO[j] + nE[j]);
        }

        if (a[i] % 2 == 1) {
            for (int j = a[i]; j <= A; ++j) {
                cur += nE[j];
            }
        } else {
            for (int j = a[i]; j <= A; ++j) {
                cur += nO[j];
            }
        }

        ans += cur / 2;

        // Updating the thing
        for (int j = A; j >= 0; --j) {
            s[min(A, j + a[i])] += (Z(a[i]) + j) * (nE[j] + nO[j]);
            if (a[i] % 2 == 0) {
                nE[min(A, j + a[i])] += nE[j];
                nO[min(A, j + a[i])] += nO[j];
            } else {
                nE[min(A, j + a[i])] += nO[j];
                nO[min(A, j + a[i])] += nE[j];
            }
        }

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
