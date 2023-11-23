#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printArray(const vector<int> &a) {
    for (int x: a) {
        if (x == 0) {
            cout << "_ ";
        } else {
            cout << x << ' ';
        }
    }
    cout << '\n';
}

vector<int> solve(int n) {
    vector<int> a(2*n - 1);
    for (int i = 0; i < n; ++i) {
        a[2*i] = i + 1;
    }

    vector<int> indices;
    indices.reserve(n - 1);
    for (int i = 1; i < 2*n - 1; i += 2) {
        indices.push_back(i);
    }

    // printArray(a);
   
    while (!indices.empty()) {
        int x = a.back();
        a.pop_back();
        int i = indices.back();
        indices.pop_back();
        a[i] = x;
        // printArray(a);
    }

    return a;
}

// 0 + multiples of 2
// 2/2 + multiples of 4
//  + multiples of 8
// 1 => 0
// 3 => 1
// 5 => 3
// 7 => 4

// n and index
ll solve2(ll n, int q) {
    if (n % 2 == 1) {
        if (q % 2 == 0) {
            return q / 2 + 1;
        } else {
            n /= 2;
            q = (q + 1) / 2;
            return n + solve2(n + 1, q);
        }
    } else {
        // n is even
        if (q % 2 == 0) {
            return q / 2 + 1;
        } else {
            n /= 2;
            q /= 2;
            return n + solve2(n, q);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector ans14 = solve(14);
    printArray(ans14);
    for (int i = 1; i < 14; i += 2) {
        cout << ans14[i] - 7 << ' ';
    }
    cout << '\n';

    printArray(solve(6));
    printArray(solve(7));

    return 0;
}