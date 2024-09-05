#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum class CharState {
    ZERO = 0,
    ODD = 1,
    EVEN = 2
};

using State = array<CharState, 26>;

void print(const State &s) {
    for (int i = 0; i < 26; ++i) {
        cerr << int(s[i]);
    }
    cerr << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    cerr << "abcdefghijklmnopqrstuvwxyz\n";

    vector<State> a(n);
    for (auto &v: a) {
        string s;
        cin >> s;

        vector<int> cnt(26);
        for (char c: s) {
            ++cnt[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) {
                v[i] = CharState::ZERO;
            } else if (cnt[i] % 2 == 0) {
                v[i] = CharState::EVEN;
            } else {
                v[i] = CharState::ODD;
            }
        }
    }

    map<State, int> cnt;
    ll ans = 0;
    for (auto &v: a) {
        cnt[v]++;

        print(v);

        State req;
        for (int i = 0; i < 26; ++i) {
            if (v[i] == CharState::ODD) {
                req[i] = CharState::EVEN;
            } else {
                req[i] = CharState::ODD;
         
            }
        }

        print(req);
        cerr << '\n';

        for (int i = 0; i < 26; ++i) {
            if (v[i] == CharState::ZERO) {
                CharState old = req[i];
                req[i] = CharState::ZERO;
                if (cnt.find(req) != cnt.end()) {
                    ans += cnt.at(req);
                }
                req[i] = old;
            }
        }
    }

    cout << ans;

    return 0;
}
