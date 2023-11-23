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

    vector<int> st;
    for (int i = 0; i < n; ++i) {
        if (st.empty() or st.back() <= a[i]) {
            st.push_back(a[i]);
        } else {
            *upper_bound(st.begin(), st.end(), a[i]) = a[i];
        }
    }

    cout << st.size() << '\n';

    return 0;
}
