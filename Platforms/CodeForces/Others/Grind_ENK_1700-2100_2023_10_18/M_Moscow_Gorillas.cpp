#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n), pA(n), pB(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pA[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        pB[b[i]] = i;
    }

    // When can the MEX be equal to i?
    // If we take all elements from 0, i-1 and then NOT take i

    auto tri = [](int l) {
        return 1LL * l * (l + 1) / 2;
    };

    int l = min(pA[0], pB[0]), r = max(pA[0], pB[0]);

    ll ans = tri(l) + tri(n - 1 - r);
    ans += tri(r - l - 1);  // Middle elements
    // cerr << "Initial ans: " << ans << '\n';
    for (int i = 1; i < n; ++i) {
        // How to make mex equal to i + 1
        // We HAVE to take l, r
        l = min(l, min(pA[i-1], pB[i-1]));
        r = max(r, max(pA[i-1], pB[i-1]));
        
        // cerr << "i: " << i << "  =>  ";
        // cerr << "l: " << l << ", r: " << r << '\n';

        if (l <= pA[i] and pA[i] <= r) {
            continue;
        } else if (l <= pB[i] and pB[i] <= r) {
            continue;
        }

        int cL = 0, cR = n - 1;
        if (pA[i] < l) {
            cL = max(pA[i] + 1, cL);
        } else {
            cR = min(pA[i] - 1, cR);
        }
        if (pB[i] < l) {
            cL = max(pB[i] + 1, cL);
        } else {
            cR = min(pB[i] - 1, cR);
        }
        // cerr << "cL: " << cL << ", cR: " << cR << '\n';
        // cerr << "ans += " << 1LL * (l - cL + 1) * (r - cR + 1) << '\n';
        ans += 1LL * (l - cL + 1) * (cR - r + 1);
    }

    ans += 1;
    cout << ans << '\n';

    return 0;
}
