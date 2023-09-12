#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll s;
    cin >> n >> k >> s;

    // Max distance u can go is n - 1 in one move
    // Min distance u can go is 1 in one move

    // Range of s achievable is [k, (n - 1) * k]

    if (1LL * (n - 1) * k < s or s < k) {
        cout << "NO\n";
        return 0;
    }

    // We need to use k moves
    vector<int> ans;
    ans.reserve(k);

    int cur = 1, d = 1;
    for (int cur = 1, dest = n, d = 1; s and k; k--) {
        // We'll go full and check if it works
        int req = (dest - cur) * d;
        if (s < req) {
            req = s;
        }

        if (s - req >= k - 1) {
            s -= req;
            cur = cur + req * d;
        } else {
            s -= 1;
            cur += d;
        }
        if (cur == dest) {
            dest ^= 1 ^ n;
            d *= -1;
        }
        ans.push_back(cur);
    }

    cout << "YES\n";
    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}
