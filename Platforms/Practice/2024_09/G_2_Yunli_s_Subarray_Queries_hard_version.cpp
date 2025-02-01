#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, nQ;
    cin >> n >> k >> nQ;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += n - 1 - i;
    }

    vector<int> b(n - k + 1);
    vector<int> cnt(2 * n), cntFreq(n + 1, 0);
    cntFreq[0] = 2 * n;
    int res = 0;
    for (int i = 0; i + 1 < k; ++i) {
        cntFreq[cnt[a[i]]]--;
        res = max(res, ++cnt[a[i]]);
        cntFreq[cnt[a[i]]]++;
    }

    for (int i = 0, j = k - 1; j < n; ++i, ++j) {
        cntFreq[cnt[a[j]]]--;
        res = max(res, ++cnt[a[j]]);
        cntFreq[cnt[a[j]]]++;

        b[i] = k - res;

        cntFreq[cnt[a[i]]]--;
        cnt[a[i]]--;
        cntFreq[cnt[a[i]]]++;

        if (cntFreq[res] == 0) {
            res--;
        }
    }
    a = b;
    n = n - k + 1;

    vector<array<int, 2>> qs(nQ);
    for (auto &[l, r]: qs) {
        cin >> l >> r;
        l--, r -= k;
    }

    vector<int> c(n);
    stack<int> s;
    s.push(n);
    for (int i = n - 1; i >= 0; --i) {
        while (s.size() > 1 and a[s.top()] >= a[i]) {
            s.pop();
        }
        c[i] = s.top();
        s.push(i);
    }

    const unsigned int K = std::__lg(n);
    vector<vector<int>> st(K + 1);
    st[0] = a;
    for (int k = 1; k <= K; ++k) {
        st[k].resize(n - (1 << k) + 1);
        for (int i = 0; i + (1 << k) <= n; ++i) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
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
