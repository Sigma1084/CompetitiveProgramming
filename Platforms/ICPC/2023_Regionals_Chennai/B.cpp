#include<bits/stdc++.h>
using namespace std;
using ll = long long;

array<vector<long double>, 17> pows;
struct T: array<int, 3> {
    using Base = array<int, 3>;
    using Base::Base;

    explicit T(int b, int x, int d): Base{b, x, d} {}

    friend bool operator < (T a1, T a2) {
        auto [b1, x1, d1] = Base(a1);
        auto [b2, x2, d2] = Base(a2);
        while (int(pows[b1].size()) <= d1) {
            pows[b1].push_back(pows[b1].back() * b1);
        }
        while (int(pows[b2].size()) <= d1) {
            pows[b2].push_back(pows[b2].back() * b2);
        }
        return (pows[b1][d1+1] - 1) * (b2 - 1) * x1
               < (pows[b2][d2+1] - 1) * (b1 - 1) * x2;
    }

    friend bool operator > (T a, T b) {
        return !(a < b);
    }

    friend ostream& operator << (ostream &os, T a) {
        auto [b, x, d] = Base(a);
        return os << b << ' ' << x << ' ' << d;
    }
};

constexpr int N = 1000000;
auto preCompute() {
    array<T, N + 1> ans;
    ans[0] = T{0, 0, 0};
    int i = 1;

    priority_queue<T, vector<T>, greater<>> pq;
    for (int b = 2; b <= 16; ++b) {
        pows[b] = vector<long double>(1, 1);
        pq.push(T{b, 1, 2});
        ans[i++] = T{b, 1, 1};
    }

    while (i <= N) {
        auto cur = pq.top();
        auto [b, x, d] = T::Base(cur);
        pq.pop();

        ++x;
        if (x == b) {
            x = 1;
            ++d;
        }
        pq.push(T{b, x, d});

        if (ans[i-1] < cur) {
            ans[i++] = cur;
        }
    }

    return ans;
}
auto a = preCompute();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // for (int i = 1; i <= N; ++i) {
    //     cerr << a[i] << '\n';
    // }
    // cerr << '\n';

    return 0;
}