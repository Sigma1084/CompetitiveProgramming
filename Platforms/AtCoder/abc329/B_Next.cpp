#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    set<int> s{a.begin(), a.end()};
    a = vector<int>(s.begin(), s.end());
    a.pop_back();

    cout << a.back();

    return 0;
}
