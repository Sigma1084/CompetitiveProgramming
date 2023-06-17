#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n, k, st, ed;
    cin >> n >> k >> st >> ed;

    vb colored(n+1, false);  // Colored vertices
    for (int i=0; i<k; i++) {
        int temp; 
        cin >> temp;
        colored[temp] = true;
    }

    vvi edges(n+1);
    {
        int t1, t2;
        for (int i=0; i<n-1; i++) {
            cin >> t1 >> t2;
            edges[t1].push_back(t2);
            edges[t2].push_back(t1);
        }
    }
    
    // Code starts here
    // Use BFS and find the path from start to end

    vi path;
    {
        vi d(n, MOD);  // d(v) is the distance of v from s
        vi p(n);  // p(v) gives the parent of v in the BFS Tree
        auto bfs = [&] (int start, int end=-1) {
            queue<int> Q;
            Q.push(start);
            d[start] = 0;
            for (int i=0; i<p.size(); i++)
                p[i] = i;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (int v: edges[u]) {
                    if (d[v] != MOD) continue;  // v has already been traversed
                    d[v] = d[u] + 1;
                    p[v] = u;
                    Q.push(v);
                    if (v == end) return;  // We have reached our end
                }
            }
        };
        bfs(ed, st);

        path.pb(-1);
        int cur = st;
        while (cur != ed) {
            path.pb(cur);
            cur = p[cur];
        }
        path.pb(ed);
        path.pb(-1);
    }


    // First Step is to get the array with number of colored below it from start
    vi botNum(n+1, -1);
    auto updateBotNum = [&] (auto &&updateBotNum, int cur, int par) -> void {
        botNum[cur] = colored[cur];    
        for (int vert: edges[cur]) {
            if (vert == par) continue;
            updateBotNum(updateBotNum, vert, cur);
            botNum[cur] += botNum[vert];
        }
    }; 
    updateBotNum(updateBotNum, st, 0);

    int ans = 0;

    auto nonPathAdd = [&] (auto &&nonPathAdd, int cur, int par) -> void {
        for (int vert: edges[cur]) {
            if (vert == par) continue;
            if (botNum[vert] == 0) continue;
            ans += 2;
            nonPathAdd(nonPathAdd, vert, cur);
        }
    };

    for (int i=1; i<path.size()-1; i++) {
        for (int vert: edges[path[i]]) {
            if (vert == path[i-1] || vert == path[i+1]) continue;
            nonPathAdd(nonPathAdd, vert, path[i]);
        }
        ans += 1;
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
