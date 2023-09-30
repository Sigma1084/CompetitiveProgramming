#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int alice = (n - 11 + 1) / 2;
    int bob = (n - 11) / 2;

    string t;
    for (char c: s) {
        if (c != '8') t.push_back(c);
        else if (bob == 0) t.push_back(c);
        else bob--;
    }

    int f8 = std::find(t.begin(), t.end(), '8') - t.begin();

    if (alice >= f8) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
