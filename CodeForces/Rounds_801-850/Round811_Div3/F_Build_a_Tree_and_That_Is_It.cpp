#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve() {
    int n; cin >> n;
    int d12, d23, d31; cin >> d12 >> d23 >> d31;
    int a, b, c;

    if ((d12 + d23 + d31) % 2 == 1) {
        cout << "NO";
        return;
    }
    if (d12 + d23 + d31 + 2 > 2*n) {
        cout << "NO";
        return;
    }
    a = (d12 - d23 + d31) / 2;
    b = (d12 + d23 - d31) / 2;
    c = (-d12 + d23 + d31) / 2;

    if (a < 0 or b < 0 or c < 0) {
        cout << "NO";
        return;
    }

    // Answer Exists
    cout << "YES\n";

    bool sp = false;
    int v = 4, s;
    if (d12 + d23 == d31) {
        // 1 --> 2 --> 3
        sp = true;
        s = 1;
        for (int i=1; i<d12; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 2 << '\n';
        s = 2;
        for (int i=1; i<d23; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 3 << '\n';
    } 
    else if (d12 + d31 == d23) {
        // 2 --> 1 --> 3
        sp = true;
        s = 2;
        for (int i=1; i<d12; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 1 << '\n';
        s = 1;
        for (int i=1; i<d31; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 3 << '\n';
    }
    else if (d23 + d31 == d12) {
        // 2 --> 3 --> 1
        sp = true;
        s = 2;
        for (int i=1; i<d23; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 3 << '\n';
        s = 3;
        for (int i=1; i<d31; i++) {
            cout << s << ' ' << v << '\n';
            s = v; v++;
        }
        cout << s << ' ' << 1 << '\n';
    }
    if (sp) {
        for (; v<=n; v++) {
            cout << "1 " << v << '\n';
        }
        return;
    }

    v = 4, s = 1;
    for (int i=1; i<d12; i++) {
        cout << s << ' ' << v << '\n';
        s = v; v++;
    }
    cout << s << ' ' << 2 << '\n';
    s = d12 + 2;
    for (int i=1; i<c; i++) {
        cout << s << ' ' << v << '\n';
        s = v; v++;
    }
    cout << s << ' ' << 3 << '\n';
    for (; v<=n; v++) {
        cout << "1 " << v << '\n';
    }
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

