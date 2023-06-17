#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, x, a = 0, i, r, d = 0;
    string n;
    cin >> k >> n;
    int y[10] = {0};
    for (i = 0; i < n.size(); i++) {
        d += n[i]-'0';
        y[n[i]-'0']++;
    }
    x = k - d;
    for (i = 0; x > 0; i++) {
        r = min(y[i], (int)ceil(1.0 * x / (9-i)));
        x -= r * (9-i);
        a += r;
    }
    cout << a;
}
