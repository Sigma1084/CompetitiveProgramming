#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Store max left and min right
    multiset<int, greater<>> lefts;
    multiset<int> rights;

    int nQ;
    cin >> nQ;
    
    for (int l, r, nS = 0; nQ--; ) {
        char c;
        cin >> c;
        cin >> l >> r;

        if (c == '+') {
            nS += 1;
            lefts.insert(l);
            rights.insert(r);
        } else if (c == '-') {
            nS -= 1;
            lefts.erase(lefts.find(l));
            rights.erase(rights.find(r));
        }

        // If the max_left is greater than min_right
        if (nS >= 2 and *lefts.begin() > *rights.begin()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
