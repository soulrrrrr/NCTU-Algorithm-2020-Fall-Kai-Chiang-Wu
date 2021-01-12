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

int cases, n, d, s;
vector<pii> v;
int vis[500005];

void solve() {
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    v.clear();
    cin >> n;
    FOR(i, 0, n) {
        cin >> d >> s;
        if (d > n)
            ans += s;
        else
            v.pb({d, s});
    }
    sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.sc > b.sc; });
    int mi_i = 1;
    FOR(i, 0, v.size()) {
        REF(j, v[i].fs, mi_i) {
            if (vis[j] == 0) {
                ans += v[i].sc;
                vis[j] = 1;
                break;
            }
        }
        while (vis[mi_i]) {
            mi_i++;
        }
    }

    cout << ans << '\n';
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