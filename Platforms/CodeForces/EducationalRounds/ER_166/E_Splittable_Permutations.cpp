#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

class Z {
    int val = 0;

public:
    constexpr Z() = default;
    template<class T> constexpr Z(const T &v): val((P + v%P) % P) {}
    constexpr Z(const Z &z) = default;

    constexpr int operator ()() const { return val; }
    constexpr Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    constexpr Z inv() const { return pow(P - 2); }

    constexpr Z& operator += (Z a) {
        val += a.val; if (val >= P) val -= P; return *this; }
    constexpr Z& operator -= (Z a) {
        val -= a.val; if (val < 0) val += P; return *this; }
    constexpr Z& operator *= (Z a) {
        val = 1LL * val * a.val % P; return *this; }
    constexpr Z& operator /= (Z a) { return *this *= a.inv(); }

    friend constexpr Z operator + (Z a, Z b) { return a += b; }
    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<array<int, 2>> a(nQ);
    for (auto &[l, r]: a) {
        cin >> l;
        --l;
    }
    for (auto &[l, r]: a) {
        cin >> r;
        --r;
    }

    // Produce ord
    vector<int> lN(n + 1, n), rN(n + 1, n);
    rN[n] = lN[n] = n - 1;
    for (auto [l, r]: a) {
        if (l < r) {
            lN[l] = lN[r];
            rN[lN[r]] = l;
        } else {
            rN[r] = rN[l];
            lN[rN[l]] = r;
        }
        lN[r] = l;
        rN[l] = r;
    }

    vector<int> ord;
    ord.reserve(nQ + 1);
    ord.push_back(rN[n]);  // This is the first node
    for (int i = 0; i < nQ; ++i) {
        ord.push_back(rN[ord.back()]);
    }

    // Number of extra slots a number is providing
    vector<int> contr(n, -1);
    for (auto x: ord) {
        contr[x] = 0;
    }

    for (int i = 0; i < nQ; ++i) {
        contr[max(ord[i], ord[i + 1])]++;
    }
    contr[ord.front()]++;
    contr[ord.back()]++;

    int slots = 0;
    Z ans = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (contr[i] == -1) {
            ans *= slots;
            slots++;
        } else {
            slots += contr[i];
        }
    }

    cout << ans;

    return 0;
}
