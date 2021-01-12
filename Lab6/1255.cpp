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

int cases;
int len;
string s;
char c[505];
int dp[505][505];

void solve() {
    cin >> len >> s;
    FOR(i, 1, len + 1) {
        c[i] = s[i - 1];
    }
    memset(dp, 0, sizeof(dp));
    FOR(i, 1, len + 1) {
        dp[i][i] = 1;
    }
    FOR(i, 1, len) {             //jianghe
        FOR(j, 1, len - i + 1) { //d[j][j+i]
            dp[j][j + i] = dp[j][j] + dp[j + 1][j + i] - (c[j] == c[j + i]);
            FOR(k, j + 1, j + i) {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] - (c[j] == c[j + i]));
            }
        }
    }
    cout << dp[1][len] << '\n';
    /*FOR(i, 0, 10) {
        FOR(j, 0, 10) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }*/
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}