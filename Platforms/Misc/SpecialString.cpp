#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int deletions(int start, int end, int m) {
    return end - start + 1 - m;
}

int solve()
{
    int n;  // Number of letters in string
    cin >> n;

    string s;
    cin >> s;

    int m;
    cin >> m;

    // End pointer
    // m = 25 --> 1st position of y
    // m = 51 --> 2nd position of y

    // Code starts here

    vector<int> charPos[26];
    int endingChar = (m-1)%26;

    for (int i=0; i<n; i++) {
        char c = s[i];
        charPos[c - 'a'].push_back(i);
    }

    int currStartIndex[m];

    int answer = INT32_MAX;

    if (charPos[0].empty()) {
        return answer;
    }

    currStartIndex[0] = 0;

    // Initial Trimming
    for (int i=1; i<m; i++) {
        int l = i%26;
        currStartIndex[i] = 0;
        if (i > 25) {
            currStartIndex[i] =
        }

        if (charPos[l].empty())
            return answer;

        while (charPos[l][currStartIndex[i]] < charPos[(i-1)%26][currStartIndex[i-1]]) {
            if (currStartIndex[i] + 1 == charPos[l].size()) {
                return answer;
            }
            currStartIndex[i]++;
        }
    }

    // Outer loop iterating the positions of a
    while (currStartIndex[26 * ((m-1)/26)] < charPos[0].size()) {
        int endingIndex = charPos[endingChar][currStartIndex[m-1]];
        int startIndex = charPos[0][currStartIndex[0]];

        answer = min(answer, deletions(startIndex, endingIndex, m));

        currStartIndex[0]++;
        if (currStartIndex[0] == charPos[0].size()) {
            return answer;
        }

        // Loop iterating trimming
        for (int i=1; i<m; i++) {
            int l = i%26;

            if (charPos[l][currStartIndex[i]] > charPos[(i-1)%26][currStartIndex[i-1]])
                break;

            while (charPos[l][currStartIndex[i]] < charPos[(i-1)%26][currStartIndex[i-1]]) {
                if (currStartIndex[i] + 1 == charPos[l].size()) {
                    return answer;
                }
                currStartIndex[i]++;
            }
        }
    }

    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int ans = solve();

        if (ans == INT32_MAX) {
            cout << -1;
        } else {
            cout << ans;
        }

        cout << "\n";
    }

    return 0;
}