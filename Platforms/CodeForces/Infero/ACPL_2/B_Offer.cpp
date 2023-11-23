#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> pqMore;
    priority_queue<int, vector<int>, greater<>> pqLess;

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (auto &x: a) {
        cin >> x;
        pqMore.push(x);
        pqLess.push(x);
    }

    ll ansMore = 0, ansLess = 0;
    for (int i = 0; i < n; ++i) {
        int x = pqMore.top();
        pqMore.pop();
        ansMore += x;
        if (x > 1) {
            pqMore.push(x - 1);
        }

        x = pqLess.top();
        pqLess.pop();
        ansLess += x;
        if (x > 1) {
            pqLess.push(x - 1);
        }
    }

    cout << ansMore << ' ' << ansLess;

    return 0;
}
