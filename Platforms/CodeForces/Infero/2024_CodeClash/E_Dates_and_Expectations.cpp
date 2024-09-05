#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class Matrix {
    std::size_t n, m;
    std::vector<std::vector<T>> a;
public:
    Matrix(): n(0), m(0) {}
    Matrix(std::size_t n, std::size_t m): n(n), m(m) {
        a.resize(n, vector<T>(m));
    }
    Matrix(const std::vector<std::vector<T>> &a) {
        n = a.size();
        m = a.size() ? a[0].size() : 0;
        this->a = a;
    }
    Matrix(const Matrix &b) = default;

    friend Matrix operator+(const Matrix &a, const Matrix &b) {
        Matrix c(a);
        for (std::size_t i = 0; i < a.n; ++i) {
            for (std::size_t j = 0; j < a.m; ++j) {
                c.a[i][j] += b.a[i][j];
            }
        }
        return c;
    }

    friend Matrix operator-(const Matrix &a, const Matrix &b) {
        Matrix c(a);
        for (std::size_t i = 0; i < a.n; ++i) {
            for (std::size_t j = 0; j < a.m; ++j) {
                c.a[i][j] -= b.a[i][j];
            }
        }
        return c;
    }

    friend Matrix operator*(const Matrix &a, const Matrix &b) {
        Matrix c(a.n, b.m);
        for (std::size_t i = 0; i < a.n; ++i) {
            for (std::size_t j = 0; j < b.m; ++j) {
                for (std::size_t k = 0; k < a.m; ++k) {
                    c.a[i][j] += a.a[i][k] * b.a[k][j];
                }
            }
        }
        return c;
    }

    friend Matrix operator*(const T &a, const Matrix &b) {
        Matrix c(b);
        for (std::size_t i = 0; i < b.n; ++i) {
            for (std::size_t j = 0; j < b.m; ++j) {
                c.a[i][j] *= a;
            }
        }
        return c;
    }

    friend ostream& operator<<(ostream &os, const Matrix &a) {
        for (std::size_t i = 0; i < a.n; ++i) {
            for (std::size_t j = 0; j < a.m; ++j) {
                os << a.a[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }

    Matrix pow(unsigned long long b) const {
        Matrix ans(n, m);
        for (std::size_t i = 0; i < n; ++i) {
            ans.a[i][i] = 1;
        }
        Matrix a(*this);
        for (; b; b /= 2, a = a * a) {
            if (b % 2) {
                ans = ans * a;
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
