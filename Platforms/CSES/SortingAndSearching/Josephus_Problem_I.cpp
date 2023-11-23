#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;

    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }

    for (auto it = s.begin(); !s.empty(); ) {
        // Remove the next one
        if (++it == s.end()) {
            it = s.begin();
        }

        // Print and prepare to remove
        cout << *it << ' ';
        auto temp = it;

        // Traverse and keep
        if (++it == s.end()) {
            it = s.begin();
        }

        // Remove the current one
        s.erase(temp);
    }
    
    return 0;
}

