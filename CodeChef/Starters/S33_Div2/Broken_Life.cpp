#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n, m;
    string s, a;

    cin >> n >> m;
    cin >> s;
    cin >> a;

    // Code starts here

    int sI = 0;
    int aI = 0;
    while (sI < n && aI < m) {
        if (s[sI] == '?') {
            char c = a[aI]; // We need to avoid this character
            if (c == 'e')
                c = 'a';
            else
                c = c+1;
            s[sI] = c;
        }
        if (aI < n && s[sI] == a[aI])
            aI++;
        sI++;
    }
    if (aI == m)
        cout << -1;
    else
        cout << s;
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
