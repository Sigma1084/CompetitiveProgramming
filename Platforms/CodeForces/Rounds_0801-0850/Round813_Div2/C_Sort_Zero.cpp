#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> a;

struct DSU {
    vector<int> nodes;
    DSU(int n) { nodes.resize(n); for (int i=0; i<n; i++) nodes[i] = i; }
    union(int i, int j) { if (a[i] < a[j]) }
};

void solve() {
    int n; cin >> n;
    a.resize(n); for (auto &x: a) cin >> x;

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    
    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    
    return 0;
}

