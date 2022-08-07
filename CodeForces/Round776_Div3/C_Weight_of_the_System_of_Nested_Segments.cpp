#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct myTrio { int pos, weight, index; };
bool compareWeight (const myTrio& l, const myTrio& r) { return l.weight < r.weight; }
bool comparePos (const myTrio& l, const myTrio& r) { return l.pos < r.pos; }

void solve() {
    int n, m;
    cin >> n >> m;

    myTrio a[m];
    int i=1;
    for (auto &ele: a) {
        cin >> ele.pos;
        cin >> ele.weight;
        ele.index = i++;
    }

    // Code starts here
    sort(a, a+m, compareWeight);
    sort(a, a+2*n, comparePos);

    ll ans = 0;
    for (i = 0; i < 2*n; i++)
        ans += a[i].weight;

    cout << ans << endl;
    for (i = 0; i < n; i++)
        cout << a[i].index << " " << a[2 * n - 1 - i].index << endl;
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
