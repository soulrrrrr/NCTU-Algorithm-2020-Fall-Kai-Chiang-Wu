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

int cases, n;
int dp[1005];

struct node {
    int x, y, t, r;
} v[1005];

bool cmp(node &a, node &b) {
    return a.t < b.t;
}

void solve() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    FOR(i, 0, n) {
        cin >> v[i].x >> v[i].y >> v[i].t >> v[i].r;
    }
    sort(v, v + n, cmp);
    FOR(i, 0, n) {
        dp[i] = v[i].r;
    }
    FOR(i, 1, n) {
        FOR(j, 0, i) {
            if ((v[j].x - v[i].x) * (v[j].x - v[i].x) + (v[j].y - v[i].y) * (v[j].y - v[i].y) <= (v[i].t - v[j].t) * (v[i].t - v[j].t)) {
                dp[i] = max(dp[i], dp[j] + v[i].r);
            }
        }
    }
    int ans = dp[0];
    FOR(i, 1, n) { ans = max(ans, dp[i]); }
    //cout << dp[0] << dp[1];
    cout << ans << "\n";
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