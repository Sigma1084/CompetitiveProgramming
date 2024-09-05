#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<pair<multiset<char>, int>> arr(n);
    for (auto &[ms, a]: arr) {
        string s;
        cin >> s >> a;
        ms = multiset<char>(s.begin(), s.end());
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    // Sorted based on cost ASC

    vector<multiset<char>> taken(n);
    for (char c: s) {
        set<pair<char, int>> st{{c, 0}};

        int i = 0;
        while (i < n) {
            const auto &[ms, a] = arr[i];
            if (a and ms.count(c)) {
                break;
            }
            ++i;
        }

        if (i == n) {
            cout << -1 << '\n';
            return 0;
        }

        
    }

    return 0;
}
