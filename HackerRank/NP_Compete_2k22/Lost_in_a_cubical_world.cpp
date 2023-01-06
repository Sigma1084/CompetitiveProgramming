#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Code starts here
    double c1, c2, c3, c4;
    double temp;

    // Case 1
    temp = 3*n - x1 - x2;
    c1 = sqrt(temp*temp + (y1-y2)*(y1-y2));

    // Case 2
    temp = n + x1 + x2;
    c2 = sqrt(temp*temp + (y1-y2)*(y1-y2));

    // Case 3
    temp = 3*n - y1 - y2;
    c3 = sqrt(temp*temp + (x1-x2)*(x1-x2));

    // Case 4
    temp = n + y1 + y2;
    c4 = sqrt(temp*temp + (x1-x2)*(x1-x2));


    cout << fixed << setprecision(9) << min(min(c1, c2), min(c3, c4));
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
