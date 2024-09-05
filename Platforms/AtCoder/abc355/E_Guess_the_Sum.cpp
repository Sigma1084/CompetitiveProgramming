#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

int solve(int l, int r) {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;

    cout << solve(l, r);

    return 0;
}