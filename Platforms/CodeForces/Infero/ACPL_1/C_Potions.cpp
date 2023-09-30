#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) cin >> x;

    map<int, int> f;
    for (int x: a) {
        f[x]++;
    }

    int ans = 0;
    while (f.size()) {
        ans += f.size() - 1;
        vector<int> rem;
        for (auto [x, fr]: f) {
            f[x]--;
            if (f[x] == 0) {
                rem.push_back(x);
            }
        }

        for (int x: rem) {
            f.erase(x);
        }
    }

    cout << ans;

    return 0;
}
