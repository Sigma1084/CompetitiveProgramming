#include<iostream>
using namespace std;

int main() {
    int k, x, a = 0, i; string n; cin >> k >> n;
    int d = 0;
    int y[10] = {0};
    for (i=0; i<n.size(); i++){
        d += n[i]-'0';
        y[n[i]-'0']++;
    }
    x = k - d;
    for (i = 0; x >= 0; i++) {
        int r = x / (9-i);
        a += min(y[i], r);
        x -= r * (9-i);
    }
    cout << a;
}