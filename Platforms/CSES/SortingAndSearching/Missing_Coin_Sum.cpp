#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    long long mx = 0;
    for (auto x: a) {
        if (x <= mx + 1) {
            mx += x;
        } else {
            break;
        }
    }

    cout << mx + 1 << '\n';
    
    return 0;
}
