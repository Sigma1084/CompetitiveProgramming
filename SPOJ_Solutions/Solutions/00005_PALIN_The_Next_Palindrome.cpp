//
// Created by Sig on 24-01-2022.
//

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

void addOne(string &s) {
    int l = s.length();
    for (int i=l-1; i>0; i--) {
        if (s[i] == '9')
            s[i] = '0';
        else {
            s[i] = s[i] + 1;
            return;
        }
    }

    if (s[0] == '9') {
        s[0] = '0';
        s = '1' + s;
    }
    else
        s[0] += 1;
}

void solve()
{
    string n;
    cin >> n;

    // Code starts here

    addOne(n);

    int l = n.length();

    string fH = strSlice(n, 0, l/2);
    string sH;
    string mid;
    if (l % 2 == 0) {
        sH = strSlice(n, l/2, -1);
        mid = "";
    } else {
        sH = strSlice(n, l/2+1, -1);
        mid += n[l/2];
    }

    reverse(fH.begin(), fH.end());
    int val = fH.compare(sH);
    reverse(fH.begin(), fH.end());

    if (val == 0) {
        cout << n;
        return;
    }

    if (val > 0) {
        sH = fH;
        reverse(sH.begin(), sH.end());
        cout << fH << mid << sH;
        return;
    }

    // Now is when the Second Half is Bigger and First Half needs to be Added One
    if (l%2 == 1) {
        if (mid == "9") {
            mid = "0";
            addOne(fH);
        }
        else
            addOne(mid);
    }

    else
        addOne(fH);

    sH = fH;
    reverse(sH.begin(), sH.end());
    cout << fH + mid + sH;
}


int main() {
    int t;
    cin >> t;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
