#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int sz;
vector<int> sg;

int query(int a, int b) {
    int ans = 0;
    a += sz; b += sz;
    while (a <= b) {
        if (a % 2 == 1) ans ^= sg[a++];
        if (b % 2 == 0) ans ^= sg[b--];
        a /= 2, b /= 2;
    }
    return ans;
}

void solve() {
    int n, nQ; cin >> n >> nQ;
    sz = pow(2, (int) ceil(log2(n)));
    sg.resize(2 * sz);

    for (int i = sz; i < sz + n; i++) {
        int temp; cin >> temp;
        sg[i] = temp;
    }

    for (int beg = sz/2; beg > 0; beg /= 2) {
        for (int i = beg; i < 2*beg; i++) {
            sg[i] = sg[2*i] ^ sg[2*i+1];
        }
    }

    for (int i = 0; i < nQ; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(a-1, b-1) << '\n';
    }
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

