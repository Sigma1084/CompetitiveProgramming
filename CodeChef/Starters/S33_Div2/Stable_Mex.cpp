#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    sort(a, a+n);

    // 0 is not present
    if (a[0] != 0){
        cout << a[0] - 1;
        return;
    }

    // a[0] = 0

    // if 1 is not present then infinity
    bool isOne = false;
    for (int i=0; i<n; i++) {
        if (a[i] == 1) {
            isOne = true;
            break;
        }
    }

    if (!isOne) {
        cout << -1;
        return;
    }

    vi aa;
    aa.push_back(a[0]);
    for (int i=1; i<n; i++) {
        if (a[i] == aa[aa.size() - 1])
            continue;
        aa.push_back(a[i]);
    }

    n = aa.size();
    int ans = 0;
    int mex = 0;
    while (mex<n && aa[mex] == mex)
        mex++;

    int j;
    for (int i=mex; i<n;) {
        j = i;
        while (j<n && aa[j+1] == aa[j]+1)
            j++;
        if (j-i >= mex-1)
            ans++;
        i = j+1;
    }

    cout << ans;
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
