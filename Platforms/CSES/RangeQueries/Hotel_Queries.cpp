#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int f(int l) {
    int n = 1 << log2_floor(l);
    if(l != n){
        n = 1 << (log2_floor(l) + 1);
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 257; i++) {
        cout << i << ": " << f(i) << "\n";
    }

    return 0;
}
