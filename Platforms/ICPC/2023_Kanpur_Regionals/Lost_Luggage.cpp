#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> constraints(6);
    for(int i = 0; i < 6; i++)
        cin >> constraints[i];
    
    auto is_valid = [&](int a, int b, int c) {
        return (a >= constraints[0] && a <= constraints[1])
            && (b >= constraints[2] && b <= constraints[3])
            && (c >= constraints[4] && c <= constraints[5]);
    };

    bool found = false;
    for(int i = 1; i <= n; i++) {
        int q, r, s; cin >> q >> r >> s;
        if(is_valid(q, r, s) || is_valid(r, q, s) 
            || is_valid(r, s, q) || is_valid(q, s, r) 
            || is_valid(s, r, q) || is_valid(s, q, r))
        {
            cout << i << ' ';
            found = true;
        }
    }

    if(not found)
        cout << "MY LUGGAGE IS LOST!";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}

// 25