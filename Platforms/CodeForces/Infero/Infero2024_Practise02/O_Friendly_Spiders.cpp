#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int N = 3e5;
std::array<int, N + 1> lPF;  // Least Prime Factor
void updatePrimes() {
    iota(lPF.begin(), lPF.end(), 0);
    lPF[0] = lPF[1] = -1;
    for (int i = 2; i * i <= N; i++) {
        if (lPF[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            lPF[j] = min(lPF[j], i);
            if (lPF[j] == j) lPF[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    updatePrimes();

    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int pX, pY; cin >> pX >> pY;
    int x = a[pX - 1], y = a[pY - 1];

    if (pX == pY) {
        cout << "1\n" << pX << '\n';
        return 0;
    } else if (x == 1 or y == 1) {
        cout << -1 << '\n';
        return 0;
    } else if (x == y) {
        cout << "2\n" << pX << ' ' << pY << '\n';
        return 0;
    }

    set<int> seenPrimes;
    vector<int> pos(N + 1, -1);
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    vector<int> par(N + 1, -1);
    queue<int> q;

    par[y] = y; q.push(y);
    while (not q.empty() and par[x] == -1) {
        int uu = q.front(), u = q.front(); q.pop();
        while (u != 1) {
            int p = lPF[u]; u /= p;
            if (seenPrimes.count(p)) continue;
            seenPrimes.insert(p);
            for (int v = p; v <= N; v += p) {
                if (pos[v] == -1) continue;  // not present
                if (par[v] != -1) continue;  // visited
                par[v] = uu;
                q.push(v);
            }
        }
    }

    if (par[x] == -1) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    int cur = x;
    while (cur != y) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(y);
    for (int &i: path) i = pos[i] + 1;
    path.front() = pX; path.back() = pY;

    cout << path.size() << '\n';
    for (int i: path) cout << i << ' ';
    cout << '\n';

    return 0;
}
