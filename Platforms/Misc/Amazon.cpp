//
// Created by sig on 18/6/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(int n, string s) {
    string p2 = "";
    string ans = "";

    auto last = [](string s) -> char { return s[s.size()-1]; };
    vector<vector<int>> pos(26);
    for(int i=0; i<n; i++) pos[s[i] - 'a'].push_back(i);

    int cur = 0;
    for(int c=0; c<26; c++) {
        while (p2.size() and last(p2) <= c+'a') {
            // Adding all the before characters
            ans.push_back(last(p2));
            p2.pop_back();
        }
        for(int p=0; p<pos[c].size(); p++) {
            if (pos[c][p] < cur) continue;
            while (cur < pos[c][p]) p2.push_back(s[cur++]);
            ans.push_back(c+'a'); cur++;
        }
    }

    return ans;
}

int main() {
    string s = "garbage";
    cout << solve(s.size(), s) << "\n";
}