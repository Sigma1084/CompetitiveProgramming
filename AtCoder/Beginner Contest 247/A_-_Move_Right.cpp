#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

string strSlice(string s, int start, int end) {
    int l = s.length();
    string ans = "";

    if (end == -1)
        end = s.length();

    if (start < 0 || start >= l)
        return ans;

    if (end <= start || end > l)
        return ans;

    for (int i=start; i<end; i++)
        ans += s[i];

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    s = "0" + s;
    s = strSlice(s, 0, 4);
    cout << s << endl;

    return 0;
}
