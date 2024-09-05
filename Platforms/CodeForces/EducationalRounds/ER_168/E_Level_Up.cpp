#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<array<int, 3>>> qs(n + 1);
    for (int qInd = 0; qInd < nQ; ++qInd) {
        int i, k;
        cin >> i >> k;
        qs[k].push_back({i-1, qInd, 0});
    }
    for (auto &q: qs) {
        sort(q.begin(), q.end());
    }

    // pr[k][i] := Number of elements x >= k in the range [0, i]
    const int rN = sqrt(n) + 1;
    vector<vector<int>> pr(rN + 2, vector<int>(n + 2));
    for (int k = rN; k >= 1; --k) {
        pr[k] = pr[k + 1];
        for (int i = n - 1; i >= 0; --i) {
            pr[k][i+1] = pr[k][i+2] + (a[i] == k);
        }
        pr[k].pop_back();
    }
    pr.pop_back();

    // for (int k = 1; k <= n; ++k) {
    //     if (qs[k].empty()) continue;
    //     cerr << "k: " << k << " => [";
    //     for (auto [i, ind, ans]: qs[k]) {
    //         cerr << "(" << i << ", " << ind << "), ";
    //     }
    //     cerr << "]\n";
    // }

    // Case 1: Brute force when k <= rN
    for (int k = 1; k <= rN; ++k) {
        if (qs[k].empty()) continue;
        int qSz = int(qs[k].size());
        for (int i = 0, j = 0, q = 0; i < n and q < qSz; ++i) {
            if (a[i] > j / k) {
                ++j;
                while (q < qSz and qs[k][q][0] == i) {
                    qs[k][q++][2] = j % k == 0;
                }
            }
            while (q < qSz and qs[k][q][0] == i) {
                ++q;
            }
        }
    }

    // Case 2: Maintain pointers
    vector<int> pts;
    pts.reserve(rN + 1);
    int ptSz = rN + 1;
    for (int i = 0; i <= n; ++i) {
        pts.push_back(i);
    }
    for (int k = rN + 1; k <= n; ++k) {
        if (qs[k].empty()) continue;
        int qSz = qs[k].size();
        for (int i = 1, q = 0; i < ptSz or q < qSz; ++i) {
            // Fix point j
            pts[i] = max(pts[i], pts[i-1]);
            while (k*pts[i] <= n and pr[k*pts[i]][pts[i]] - pr[k*pts[i]][pts[i-1]] < k) {
                ++pts[i];
            }
            while (q < qSz and qs[k][q][0] < pts[i]) {
                qs[k][q++][2] = false;
            }
            while (q < qSz and qs[k][q][0] == pts[i]) {
                qs[k][q++][2] = true;
            }
        }
        while (pts.back() == n + 1) {
            pts.pop_back();
        }
        ptSz = int(pts.size());
    }

    vector<bool> anss(nQ);
    for (const auto &q: qs) {
        for (auto [i, ind, ans]: q) {
            anss[ind] = ans;
        }
    }

    for (auto x: anss) {
        cout << (x ? "YES" : "NO") << '\n';
    }

    return 0;
}
