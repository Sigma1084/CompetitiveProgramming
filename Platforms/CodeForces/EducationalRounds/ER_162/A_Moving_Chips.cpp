#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    deque<int> dq{a.begin(), a.end()};
    while (dq.size() and dq.front() == 0) {
        dq.pop_front();
    }
    while (dq.size() and dq.back() == 0) {
        dq.pop_back();
    }

    cout << count(dq.begin(), dq.end(), 0);
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
