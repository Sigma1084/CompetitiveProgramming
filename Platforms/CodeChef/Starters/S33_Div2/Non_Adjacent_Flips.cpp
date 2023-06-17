#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    // Code starts here

    bool isAllZeros = true;
    bool doubleOne = false;
    char prev = '0';


    for (char c: s) {
        if (c == '1') {
            isAllZeros = false;
            if (prev == '1')
                doubleOne = true;
            prev = '1';
        }
        else if (c == '0') {
            prev = '0';
        }
    }

    if (isAllZeros) {
        cout << 0;
    }
    else if (doubleOne) {
        cout << 2;
    }
    else {
        cout << 1;
    }
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
