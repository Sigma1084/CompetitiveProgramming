#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

/**
 * We represent the operation of (a, b) using the vector [a, b, 1]
 * 
 * Multiplication by [a, b, 1] is
 * [a, 0, 0]
 * [0, a, b]
 * [0, 0, 1]
 * 
 * Identity is [1, 0, 1] corresponds to (1, 0) and identity matrix
 * 
 * For inverting, we assume a'(ax + b) + b' = x
 * and solve for a' and b' to get a' = 1/a and b' = -b/a
 * Thus, (a, b, 1)^-1 = (1/a, -b/a, 1)
 * [1/a, 0, 0]
 * [0, 1/a, -b/a]
 * [0, 0, 1]
 * 
 * Suppose we currently have [A, B, 1]
 * 
 * Applying the operation on the cuurent value
 * will be equivalent to left multiplying the matrix
 * [a, 0, 0] [A, 0, 0]  =  [aA, 0, 0]
 * [0, a, b] [0, A, B]  =  [0, aA, aB + b]
 * [0, 0, 1] [0, 0, 1]  =  [0, 0, 1]
 * 
 * Deleting the first operation is equivalent to
 * right multiplying the inverse of the matrix corresponding
 * to the first operation
 * [A, 0, 0] [1/a, 0, 0]     =  [A/a, 0, 0]
 * [0, A, B] [0, 1/a, -b/a]  =  [0, A/a, B - Ab/a]
 * [0, 0, 1] [0, 0, 1]       =  [0, 0, 1]
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Z A = 1, B = 0;  // Initial values
    queue<pair<int, int>> q;

    int nQ; cin >> nQ;
    for (int t, a, b, x; nQ--; ) {
        cin >> t;
        if (t == 0) {
            cin >> a >> b;
            q.push({a, b});
            A = A * a;
            B = B * a + b;
        } else if (t == 1) {
            tie(a, b) = q.front();
            q.pop();
            B = B - A * b / a;
            A = A / a;
        } else if (t == 2) {
            cin >> x;
            cout << A * x + B << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}
