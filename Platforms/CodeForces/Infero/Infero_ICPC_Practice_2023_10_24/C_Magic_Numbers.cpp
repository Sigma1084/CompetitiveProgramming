#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    while (s.size()) {
        int n = s.size();
        if (n >= 3 and s.substr(n - 3, 3) == "144") {
            s.erase(n - 3, 3);
        } else if (n >= 2 and s.substr(n - 2, 2) == "14") {
            s.erase(n - 2, 2);
        } else if (n >= 1 and s.substr(n - 1, 1) == "1") {
            s.erase(n - 1, 1);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
