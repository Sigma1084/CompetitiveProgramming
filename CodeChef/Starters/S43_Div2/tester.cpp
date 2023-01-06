#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 100;
    auto bitsBefore = [] (int n) -> vector<int> {
        vector<int> d;
        for (int i=1; i<=n; i++) {
            for (int cur = 0, k = i; k > 0; k /= 2, cur++) {
                if (k % 2 == 0) continue;
                if (d.size() == cur) d.push_back(0);
                d[cur] += 1;
            }
        }

        return d;
    };

    for (int i=2; i<=100; i+=2) {
        auto x = bitsBefore(i); cout << i << ": ";
        for (auto e: x) cout << e << ' '; cout << '\n';
    }
}