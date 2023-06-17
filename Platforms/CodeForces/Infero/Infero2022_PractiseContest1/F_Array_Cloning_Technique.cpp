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
    vi freqs;

    int currFreq = 1;
    int currEle = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] == currEle)
            currFreq++;
        else {
            freqs.push_back(currFreq);
            currFreq = 1;
            currEle = a[i];
        }
    }
    freqs.push_back(currFreq);
    sort(freqs.begin(), freqs.end());

    int maxFreq = freqs[freqs.size()-1];

    int ans = n-maxFreq;
    while (maxFreq < n) {
        ans++;  // Adding the Clone
        maxFreq *= 2;
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
