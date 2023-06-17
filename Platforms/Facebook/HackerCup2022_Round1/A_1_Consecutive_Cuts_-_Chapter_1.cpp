#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int i = 0;
    while (i < n and a[0] != b[i]) i++;

    if (k == 0) {
        if (i == 0) cout << "YES";
        else cout << "NO";
        return;
    }

    if (k == 1 and i == 0) {
        cout << "NO";
        return;
    }

    // n = 2  =>  Only 1 way to make cut
    if (n == 2) {
        if (k%2 == i) cout << "YES";
        else cout << "NO";
        return;
    }


    // n > 3  =>  Only 2 ways to make cut
    for (int j = 1; j < n; j++) {
        if (a[j] != b[(i+j)%n]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("consecutive_cuts_chapter_1_input.txt", "r", stdin);
    freopen("consecutive_cuts_chapter_1_output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

