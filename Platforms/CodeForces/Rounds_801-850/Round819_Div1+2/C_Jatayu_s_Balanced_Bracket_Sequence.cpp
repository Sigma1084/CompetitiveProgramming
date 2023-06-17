#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n;
vector<int> p;

int Find(int i) {
    if (p[i] == i) return i;
    return p[i] = Find(p[i]);
}

void Union(int i, int j) {
    if (Find(i) == Find(j)) return;
    p[i] = j;
}

void solve() {
    cin >> n; n *= 2;
    string s; cin >> s;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' and i and s[i-1] == ')') Union(i, i-1);
        if (s[i] == '(') st.push(i);
        else { Union(i, st.top()); st.pop(); }
    }

    set<int> un;
    for (int i = 0; i < n; i++) {
        un.insert(Find(i));
    }

    cout << un.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

