#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
        if (a[i] + a[j] <= x) {
            i++;
            j--;
            ans++;
        } else {
            j--;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
