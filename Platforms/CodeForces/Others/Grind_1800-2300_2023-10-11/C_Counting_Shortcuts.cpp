#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--; t--;

    vector<vector<int>> e(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> dist(n, -1);
    vector<int> ord;
    vector<Z> dp1(n, 0), dp2(n, 0);

    queue<pair<int, int>> q;  // [distance, node]

    // Fix the distances from s to all nodes
    q.emplace(0, s);
    while (!q.empty()) {
        auto [d, u] = q.front();
        q.pop();
        if (dist[u] != -1) continue;
        ord.push_back(u);
        dist[u] = d;
        for (auto v: e[u]) {
            q.emplace(d+1, v);
        }
    }

    // Update dp1 and dp2
    dp1[s] = 1;
    for (int u: ord) {
        for (auto v: e[u]) {
            if (dist[v] == dist[u] + 1) {
                dp1[v] += dp1[u];
            } else if (dist[v] == dist[u]) {
                dp2[v] += dp1[u];
            }
        }
    }

    for (int u: ord) {
        for (int v: e[u]) {
            if (dist[v] == dist[u] + 1) {
                dp2[v] += dp2[u];
            }
        }
    }

    cout << dp1[t] + dp2[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
