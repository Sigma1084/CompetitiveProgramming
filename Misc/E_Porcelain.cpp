#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi combine(const vi &a, const vi &b) {
    int n = a.size() - 1, m = b.size() - 1;
    vi c(n + m + 1);
    for (int i=0; i<=n+m; i++) {
        // Select i items
        for (int j=0; j<=i; j++) 
            c[i] = max(c[i], a[j] + b[n+m - j]);
    }
    return c;
}

void solve() {
    int n, m; cin >> n >> m;

    // Takes n*n space
    vector<vi> data(n);  // n := number of shelfs
    for (auto &a: data) {
        int size; cin >> size;
        a = vi(size);
        for (auto &i: a) cin >> i;
    }
    
    // Optimized Data
    vector<vi> optim;
    for (auto const &a: data) {
        int sz = a.size();
        vi prefSum(sz + 1), sufSum(sz + 1);
        for (int i=0; i<sz; i++) prefSum[i+1] = prefSum[i] + a[i];
        for (int i=0; i<sz; i++) sufSum[i+1] = sufSum[i] + a[sz-1-i];

        vi ans(sz + 1);
        for (int i=1; i<=sz; i++) {
            // ans[i] is calculated
            // i items can be selected
            for (int j=0; j<=i; j++) {
                // j from beginning => prefSum[j]
                // i-j from end => sufSum[i-j]
                ans[i] = max(ans[i], prefSum[j] + sufSum[i-j]);
            }
        }

        optim.push_back(ans);
    }

    sort(optim.begin(), optim.end(), 
        [](vi &a, vi &b) { return a.size() <= b.size(); });

    while (optim.size() > 1) {
        vector<vi> newOptim;
        for (int i=0; i<optim.size(); i+=2) {
            vi c = combine(optim[i], optim[i+1]);
            optim[i].clear(), optim[i+1].clear();
            newOptim.push_back(c);
        }
        if (optim.size() % 2 == 1) {
            newOptim.push_back(optim.back());
            optim.back().clear();
        }
        optim.clear();
        optim = newOptim;
    }

    for (auto &i: optim.back()) cout << i << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
