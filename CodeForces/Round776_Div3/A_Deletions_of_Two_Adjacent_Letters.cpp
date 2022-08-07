#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve() {
    string s;
    cin >> s;

    char c;
    cin >> c;

    // Code starts here
    for (int i=0; i<s.length(); i+=2) {
        if (s[i] == c) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
