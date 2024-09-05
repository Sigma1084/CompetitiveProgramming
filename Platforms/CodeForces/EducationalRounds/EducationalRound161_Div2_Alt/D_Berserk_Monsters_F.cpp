#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), d(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: d) {
        cin >> x;
        ++x;
    }

    // The moment x becomes 0, guy loses
    vector<int> timesVec(n);
    set<array<int, 4>> times;  // [time, index, damage, timeUpdated]
    set<int> alive;  // All alive
    for (int i = 0; i < n; ++i) {
        int dmg = (i > 0 ? a[i-1] : 0) + (i+1 < n ? a[i+1] : 0);
        times.insert({(d[i] + dmg - 1) / dmg, i, dmg, 0});
        timesVec[i] = (d[i] + dmg - 1) / dmg;
        alive.insert(i);
        cerr << "i = " << i << ", time = " << (d[i] + dmg - 1) / dmg << ", dmg = " << dmg << '\n';
    }
    cerr << '\n';

    vector<int> ans(n + 1);

    int cur = 0;
    while (!times.empty() and (*times.begin())[0] <= n) {
        cur = (*times.begin())[0];
        cerr << "cur = " << cur << "\n";

        vector<int> toErase;
        cerr << "erasing: ";
        while (!times.empty() and times.begin()->at(0) == cur) {
            int i = times.begin()->at(1);
            toErase.push_back(i);
            alive.erase(i);
            times.erase(times.begin());
            cerr << i << ' ';
        }
        ans[cur] = toErase.size();
        cerr << '\n';

        cerr << "toErase.size() = " << toErase.size() << ", ";


        set<int> toChange;
        for (auto i: toErase) {
            // Left alive and right alive

            // Check if there's a left alive
            if (alive.lower_bound(i) != alive.begin()) {
                int j = *prev(alive.lower_bound(i));
                toChange.insert(j);
            }

            // Check if there's a right alive
            if (alive.upper_bound(i) != alive.end()) {
                int j = *alive.upper_bound(i);
                toChange.insert(j);
            }
        }

        cerr << "toChange.size() = " << toChange.size() << '\n';

        for (auto i: toChange) {
            auto it = times.lower_bound({timesVec[i], i, 0, 0});
            auto [time, idx, dmg, prevTime] = *it;
            times.erase(it);

            cerr << "i = " << i << ", time = " << time << ", idx = " << idx << ", dmg = " << dmg << ", prevTime = " << prevTime << '\n';

            assert(idx == i);


            // Update d[i]
            d[i] -= dmg * (cur - prevTime);

            // Update dmg
            dmg = 0;
            if (alive.lower_bound(i) != alive.begin()) {
                int j = *prev(alive.lower_bound(i));
                dmg += a[j];
            }
            if (alive.upper_bound(i) != alive.end()) {
                int j = *alive.upper_bound(i);
                dmg += a[j];
            }

            // Update time
            time = cur + (d[i] + dmg - 1) / dmg;
            timesVec[i] = time;

            // Insert back
            times.insert({time, idx, dmg, cur});
        }

        cerr << "times.size() = " << times.size() << '\n';
        cerr << "alive.size() = " << alive.size() << '\n';
        cerr << '\n';
    }

    cerr << "cur = " << cur << '\n';

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
