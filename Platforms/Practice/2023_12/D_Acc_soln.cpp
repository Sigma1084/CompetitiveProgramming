#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<map>
#include<math.h>
#include<set>
#include<stack>
#include<algorithm>
#define int long long
#define INF 1e17
#define MOD1 998244353
#define MOD2 1000000007
#define N 2000005
using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c = count(s.begin(), s.end(), '1');
        int pairs = 0;
        for (int j = 1; j < m; j++) {
            if (s[j] == '1' && s[j - 1] == '1') pairs++, j++;
        }
        lo += c - min(m / 4, pairs);
        cerr << c - min(m / 4, pairs) << ' ';
        pairs = 0;
        for (int j = 1; j < m; j++) {
            if (s[j] != '1' || s[j - 1] != '1') pairs++, j++;
        }
        hi += c - max(0, m / 4 - pairs);
        cerr << c - max(0, m / 4 - pairs) << '\n';
    }
    cout << lo << ' ' << hi << '\n';
}
