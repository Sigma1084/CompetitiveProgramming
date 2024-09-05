/**
 * @file game_of_ways.cpp
 */

#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1e9 + 7;

/**
 * We need to survive for T seconds on m runways
 * After time t, suppose the number of ways in which u can end at
 * runway i be equal to dp[t][i]
 * Notice that dp[t+1] can be obtained using dp[t]
 *
 * For m = 5,
 * dp[t+1][4] = dp[t][1] + dp[t][3] + dp[t][5]
 * This is because we can go from 1 to 4, 3 to 4 and 5 to 4
 *   but not from 2 to 4 or 4 to 4
 *
 * This approach however can't be done since the constraints are large
 * Hence, we improve it
 * Also notice that these transitions can be represented by a matrix
 * multiplication
 *
 * eg. m = 5
 * dp[t+1][1]   [ 0  1  1  1  1 ] dp[t][1]
 * dp[t+1][2]   [ 1  0  1  0  1 ] dp[t][2]
 * dp[t+1][3] = [ 1  1  0  1  1 ] dp[t][3]
 * dp[t+1][4]   [ 1  0  1  0  1 ] dp[t][4]
 * dp[t+1][5]   [ 1  1  1  1  0 ] dp[t][5]
 *
 * Basically, we can compute dp[T] = A^(T - 1) dp[1]
 * where dp[1] = transpose([1  1  1  1  1]) since we can start from any state
 *
 * We can then compute A^(T - 1) using binary exponentiation
 */

using ll = long long;
using Matrix = vector<vector<ll>>;

/**
 * @param m1 Matrix of shape (n, m)
 * @param m2 Matrix of shape (m, p)
 * @return Matrix of shape (n, p)
 */
Matrix mult(const Matrix &m1, const Matrix &m2) {
    // Make sure the matrices are non-empty
    assert(!m1.empty() and !m1[0].empty() and !m2.empty() and !m2[0].empty());

    // Make sure the multiplication is valid
    assert(m1[0].size() == m2.size());

    int n = int(m1.size());
    int m = int(m1[0].size());
    int p = int(m2[0].size());
    Matrix res(n, vector(p, 0LL));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                res[i][j] += (m1[i][k] * m2[k][j]) % P;
                res[i][j] %= P;
            }
        }
    }

    return res;
}

/**
 * @return mat^b
 */
Matrix pow(Matrix mat, ll b) {
    // Make sure the matrix is non-empty
    assert(!mat.empty() and !mat[0].empty());

    // Make sure it's a square matrix
    assert(mat.size() == mat[0].size());

    int n = int(mat.size());

    // Initially an identity matrix
    Matrix res(n, vector(n, 0LL));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1) {
            res = mult(res, mat);
        }
        mat = mult(mat, mat);
        b /= 2;
    }

    return res;
}

int solve(int T, int m) {
    // We need to construct the transition matrix
    Matrix mat(m, vector(m, 0LL));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            // When can we go from i to j?
            // When gcd(i, j) = 1
            if (gcd(i + 1, j + 1) == 1) {
                mat[i][j] = 1;
            }
        }
        mat[i][i] = 0;
    }

    // Now we need to compute the initial values, which is a row matrix
    Matrix init(m, vector(1, 1LL));  // (m * 1) matrix

    // final = mat^(T-1) * init
    Matrix final = mult(pow(mat, T - 1), init);

    // We just need to add all the values in final now
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = (ans + final[i][0]) % P;
    }

    return int(ans);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    int T, m, ans;

    // We have 2 runways, so start from either and always be on the run
    T = 10, m = 2;
    ans = solve(T, m);
    cerr << ans << '\n';
    assert(ans == 2);

    T = 3, m = 3;
    ans = solve(T, m);
    cerr << ans << '\n';
    assert(ans == 12);

    return 0;
}
