#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    {
        bool f = false; 
        for (auto &x: a) {
            if (x % 5 == 0) { f = true; break; }
        }

        if (f) {
            for (auto &x: a) {
                if (x % 5 != 0) {
                    cout << "No";
                    return;
                } if (x % 10 == 5) x += 5;
            }
            for (int i = 1; i < n; i++) if (a[i] != a[i-1]) {
                cout << "No";
                return;
            }
            cout << "Yes";
            return;
        }
    }

    for (auto &x: a) while (x % 10 != 2) x += x%10;

    bool ok = (a[0]/10) % 2;
    for (auto &x: a) {
        if ((x/10) % 2 != ok) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    
    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    
    return 0;
}

