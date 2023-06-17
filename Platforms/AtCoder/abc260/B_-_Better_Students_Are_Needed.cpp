#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 1; i <= n; i++)
        cin >> a[i-1][0];
    for (int i = 1; i <= n; i++)
        cin >> a[i-1][1];
    for (int i = 1; i <= n; i++)
        a[i-1][2] = i;
    
    sort(a.begin(), a.end(),
        [] (const vector<int> &v1, const vector<int> &v2) {
            if (v1[0] > v2[0]) return true;
            if (v1[0] < v2[0]) return false;
            return v1[2] < v2[2];
        });

    sort(a.begin() + x, a.end(),
        [] (const vector<int> &v1, const vector<int> &v2) {
            if (v1[1] > v2[1]) return true;
            if (v1[1] < v2[1]) return false;
            return v1[2] < v2[2];
        });
    
    sort(a.begin() + x+y, a.end(),
        [] (const vector<int> &v1, const vector<int> &v2) {
            if (v1[0] + v1[1] > v2[0] + v2[1]) return true;
            if (v1[0] + v1[1] < v2[0] + v2[1]) return false;
            return v1[2] < v2[2];
        });

    sort(a.begin(), a.begin() + x+y+z,
        [] (const vector<int> &v1, const vector<int> &v2) {
            return v1[2] < v2[2];
        });
    
    for (int i = 0; i < x+y+z; i++) {
        cout << a[i][2] << '\n';
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

