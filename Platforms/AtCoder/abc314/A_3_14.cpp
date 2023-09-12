#include <bits/stdc++.h>
using namespace std;

string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string ans = pi.substr(0, n + 2);
    cout << ans;

    return 0;
}
