#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef pair<int, int> pii;
void solve() {
    int n; cin >> n;
    /**
     * a = {time, arrival/departure, index}
     */

    vector<vector<int>> data(2 * n, vector<int>(3));
    for (int i=0; i<2*n; i+=2) {
        cin >> data[i][0]; data[i][1] = -1; data[i][2] =  i/2;  // Arrival
        cin >> data[i+1][0]; data[i+1][1] = 1; data[i+1][2] = i/2;  // Departure
    }
    sort(data.begin(), data.end());

    int maxRoomNo = 0;
    set<int> empty;  // Set of all empty rooms
    vector<int> rooms(n);  // Room alloted to person i

    for (auto &x: data) {
        if (x[1] == -1) {
            // Arrival
            int num;
            if (empty.empty()) num = ++maxRoomNo;
            else { num = *empty.begin(); empty.erase(empty.begin()); }
            rooms[x[2]] = num;
        } else {
            // Departure
            empty.insert(rooms[x[2]]);
        }
    }

    cout << empty.size() << '\n';
    for (auto &x: rooms) cout << x << ' '; cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    
    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    
    return 0;
}

