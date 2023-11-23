#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    int x; cin >> x;
    return x;
}

void submit(int i, int j = -1) {
    if (j == -1) j = i;
    cout << "! " << i + 1 << ' ' << j + 1 << endl;
}

void solve() {
    int n; cin >> n;

    auto do4 = [&] (int i, int j, int k, int l) {
        int f0 = ask(j, k, l);
        int f1 = ask(i, k, l);
        int f2 = ask(i, j, l);
        int f3 = ask(i, j, k);
        int mx = max({f0, f1, f2, f3});
        set<int> ans;
        vector<pair<int, int>> pairs = {{f0, i}, {f1, j}, {f2, k}, {f3, l}};
        for (auto [f, idx]: pairs) {
            if (f != mx) {
                ans.insert(idx);
            }
        }
        return ans;
    };

    set<int> pos;
    for (int i = 0; i < n; ++i) {
        pos.insert(i);
    }

    while (pos.size() > 2) {
        for (int i = 0; i < n and pos.size() < 4; ++i) {
            pos.insert(i);
        }

        vector posVec = vector(pos.begin(), pos.end());
        pos.clear();

        int i;
        for (i = 0; i + 3 < int(posVec.size()); i += 4) {
            auto ans = do4(posVec[i], posVec[i + 1], posVec[i + 2], posVec[i + 3]);
            for (auto idx: ans) {
                pos.insert(idx);
            }
        }

        for (; i < int(posVec.size()); ++i) {
            pos.insert(posVec[i]);
        }
    }

    for (int i = 0; i < n and pos.size() < 2; ++i) {
        pos.insert(i);
    }

    vector posVec = vector(pos.begin(), pos.end());
    submit(posVec[0], posVec[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
