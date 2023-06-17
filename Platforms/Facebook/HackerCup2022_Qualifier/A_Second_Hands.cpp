#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &x: a) cin >> x;

    bool ok = true;

    if (2*k < n) ok = false;

    map<int, int> m;
    for (auto &i: a) {
        m[i]++;
        if (m[i] > 2) ok = false;
    }
    
    if (ok) cout << "YES";
    else cout << "NO";
}

int main() {
    // ifstream in("second_hands_validation_input.txt");
    // ofstream out("second_hands_validation_output.txt");

    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    // freopen("second_hands_validation_input.txt", "r", stdin);
    // freopen("second_hands_validation_output.txt", "w", stdout);

    freopen("second_hands_input.txt", "r", stdin);
    freopen("second_hands_output.txt", "w", stdout);

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

