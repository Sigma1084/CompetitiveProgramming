#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using ordered_set = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<T>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, nQ;
    cin >> n >> m >> nQ;

    vector<int> numOcc(m);
    // indsWithOcc[0] = list of indices with 0 occupancy
    vector<vector<int>> indsWithOcc(m + 1);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        numOcc[x - 1]++;
    }
    for (int i = 0; i < m; ++i) {
        indsWithOcc[numOcc[i]].push_back(i);
    }
    for (auto &v: indsWithOcc) {
        sort(v.begin(), v.end());
    }

    // [index, query, answer]
    vector<array<ll, 3>> queries(nQ);
    int q = 0;
    for (auto &[index, k, ans]: queries) {
		index = q++;
		cin >> k;
		ans = 0;
	}
    sort(queries.begin(), queries.end(),
        [](const auto &a, const auto &b) {
            if (a[1] != b[1]) return a[1] < b[1];
            if (a[0] != b[0]) return a[0] < b[0];
            return a[2] < b[2];
        });

    // Real shit
    ordered_set<int> os;
    ll cur = 0;
	q = 0;

    for (int i = 0; i < m and q < nQ; i++) {
        // Make everything having i + 1 occurrences
        for (auto x: indsWithOcc[i]) os.insert(x);
        // We need to go os.size() steps to make
        for (; q < nQ and queries[q][1] - cur <= ll(os.size()); q++) {
            queries[q][2] = *os.find_by_order(queries[q][1] - cur - 1);
        }
        cur += os.size();
    }

    // We have all the m cities cycling now

    // Now for the remaining
    for (; q < nQ; ++q) {
        auto &[index, k, ans] = queries[q];
        ans = (k - cur - 1) % m;
    }

    sort(queries.begin(), queries.end());
    for (auto [index, k, ans]: queries) {
        cout << ans + 1 << '\n';
    }

    return 0;
}
