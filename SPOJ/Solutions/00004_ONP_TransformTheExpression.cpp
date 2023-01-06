/*
 * Input:
 * 3
 * (a+(b*c))
 * ((a+b)*(z+x))
 * ((a+t)*((b+(a+c))^(c+d)))

 * Output:
 * abc*+
 * ab+zx+*
 * at+bac++cd+^*
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    string s;
    cin >> s;

    // Contains all the characters that are to be added eventually
    stack<char> operators;

    string ans = "";

    char temp;

    // Code starts here
    // Iterating through every character in s
    for (char c: s) {

        switch (c) {
            case '(': continue;
            // When we close a bracket, that is when we append the operator
            case ')':
                temp = operators.top();
                ans += temp;

                operators.pop();
                continue;

            // When we encounter an operator, we push it inside a stack and pop it when the bracket ends
            case '+': case '-': case '*': case '/': case '^':
                operators.push(c);
                continue;

            // This is when we encounter a letter
            default:
                ans += c;
        }
    }

    cout << ans;
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
