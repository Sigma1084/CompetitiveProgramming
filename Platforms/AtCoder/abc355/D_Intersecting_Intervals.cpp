#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1;
    std::cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[l, r]: a) {
        std::cin >> l >> r;
    }
    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<>> pq;
    ll ans = 0;
    for (auto [l, r]: a) {
        while (pq.size() and pq.top() < l) {
            pq.pop();
        }
        ans += pq.size();
        pq.push(r);
    }

    std::cout << ans;
 
    return 0;
}
