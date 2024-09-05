#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * @brief maxMedian
 * Given two arrays with odd length n, find the maximum median of an array
 * a such that lb <= a <= ub element-wise and sum(a) <= maxSum.
 */
int maxMedian(const vector<int> &lb, const vector<int> &ub, ll maxSum) {
    /**
     * Start by a = lb
     * Choose an index i such that a[i] is not the maximum possible
     * and increase a[i] by 1 until sum(a) <= maxSum.
     * 
     * The possible medians are in an interval without gaps.
     * Hence, we can apply binary search to find the maximum median.
     */

    int n = lb.size();
    assert(n & 1);  // n is odd

    int k = (n - 1) / 2;
    // We need k elements to the left and right of the median

    vector<pair<int, int>> lub(n);
    for (int i = 0; i < n; ++i) {
        lub[i] = {lb[i], ub[i]};
    }
    sort(lub.begin(), lub.end());

    ll l = lub[k].first;

    vector<int> a = ub;
    sort(a.begin(), a.end());
    ll r = a[k];

    if (accumulate(lb.begin(), lb.end(), 0LL) > maxSum) {
        return -1;  // Impossible case
    }

    // The median now lies in [l, r]
    auto isPos = [&](int m) -> bool {
        // We need k elements <= m and k elements >= m
        int numLessForSure = 0, numMoreForSure = 0;
        vector<int> validLs;
        ll s = m;
        for (int i = 0; i < n; ++i) {
            if (lub[i].second < m) {
                // Always goes to the left
                // Might as well make it as small as possible
                s += lub[i].first;
                numLessForSure++;
            } else if (lb[i] > m) {
                // Always goes to the right
                // Might as well make it as small as possible
                s += lub[i].first;
                numMoreForSure++;
            } else {
                validLs.push_back(lub[i].first);
            }
        }

        if (numLessForSure > k or numMoreForSure > k) {
            return false;
        }

        reverse(validLs.begin(), validLs.end());

        // Since the ls are sorted, take the ones with the smallest lb
        while (numLessForSure < k) {
            s += validLs.back();
            validLs.pop_back();
            ++numLessForSure;
        }

        s += (k - numMoreForSure) * m;

        // This is the minimum sum possible for an array with median m
        return s <= maxSum;
    };

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (isPos(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lb(n), ub(n);
    for (auto &x: lb) {
        cin >> x;
    }
    for (auto &x: ub) {
        cin >> x;
    }

    ll maxSum;
    cin >> maxSum;

    return 0;
}
