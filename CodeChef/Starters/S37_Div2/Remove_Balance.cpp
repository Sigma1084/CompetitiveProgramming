#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    stack<char> sc;
    stack<int> si;
    vb taken(n, false);

    for (int i=0; i<n; i++) {
        char c = s[i];
        if (c == '(') {
            sc.push(c);
            si.push(i);
            continue;
        }

        // c = ')'

        if (!sc.empty() && sc.top() == '(') {
            taken[si.top()] = true;
            taken[i] = true;
            sc.pop();
            si.pop();
        } else {
            sc.push(c);
            si.push(i);
        }
    }

    int ops = 0;
    int finNum = 0;
    bool cur = false;
    for (bool b: taken) {
        if (!b) finNum++;
        if (cur == b) continue;
        if (b) ops++;
        cur = b;
    }

    cout << finNum << " " << ops;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
