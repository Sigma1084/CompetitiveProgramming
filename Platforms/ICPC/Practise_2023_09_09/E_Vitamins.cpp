#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<string, 7> types = {{
        "A", "B", "C", "AB", "BC", "AC", "ABC"
    }};

    array<int, 7> m;
    m.fill(1e9);

    for (string s; n--; ) {
        int p;
        cin >> p >> s;

        sort(s.begin(), s.end());
    }



    return 0;
}
