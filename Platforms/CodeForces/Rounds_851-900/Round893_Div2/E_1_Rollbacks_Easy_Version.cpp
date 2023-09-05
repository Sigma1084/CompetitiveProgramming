#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

pair<int, int> ask() {
	char c; cin >> c;
	if (c == '+') {
		int x; cin >> x;
		return {1, x};
	} else if (c == '-') {
		int x; cin >> x;
		return {2, x};
	} else if (c == '!') {
		return {3, 0};
	} else if (c == '?') {
		return {4, 0};
	} else {
		assert(false);
	}
	return {0, 0};
}

int main() {
	int nQ; cin >> nQ;
	vector<pair<int, int>> q(nQ);

	for (int i = 0; i < nQ; i++) {
		q[i] = ask();
	}

	vector<int> a;
	map<int, int> f;
	map<int, int> occs;

	stack<int> st;

	for (int i = 0; i < nQ; i++) {
		if (q[i].first <= 2) st.push(i);
		if (q[i].first == 3) {
			st.pop();
			occs[st.top()] += 1;
		}
	}

	map<int, map<int, int>> ms;
	for (int i = 0; i < nQ; i++) {
		if (q[i].first == 1) {
			st.push(i);
		}
		if (q[i].first == 3) {
			st.pop();
			occs[st.top()] -= 1;
			if (occs[st.top()] == 0) {
				occs.erase(st.top());
				ms.erase(st.top());
			}
		}
	}

	return 0;
}
