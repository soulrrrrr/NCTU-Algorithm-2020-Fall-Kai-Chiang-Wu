#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2", "O3", "Ofast", "unroll-loops")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define int ll
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
#define pii pair<int, int>

int a, b;

int dp[105][10005];

int d(int k, int n) { //k eggs, max n times, max dp[k][n] floor
    if (k == 0)
        return 0;
    if (k == 1)
        return n;
    FOR(i, 2, k + 1) {
        FOR(j, 1, n + 1) {
            dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i][j - 1];
            if (dp[i][j] >= n) {
                if (i == k) {
                    return j;
                }
                break;
            }
        }
    }
    return 0;
}

void solve() {
    int ans = d(a, b);
    cout << ans << '\n';
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    FOR(i, 0, 101) {
        dp[i][1] = 1;
    }
    FOR(i, 0, 101) {
        dp[i][0] = 0;
    }
    FOR(i, 0, 10001) {
        dp[1][i] = i;
    }
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        solve();
    }
    return 0;
}