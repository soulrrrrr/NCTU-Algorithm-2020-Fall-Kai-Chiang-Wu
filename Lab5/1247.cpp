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

int cases, n, s, t;
pii v[100005];

void solve() {
    memset(v, 0, sizeof(v));
    cin >> n;
    FOR(i, 0, n) {
        cin >> v[i].fs >> v[i].sc;
    }
    sort(v, v + n, [](pii &a, pii &b) { return a.sc < b.sc; });
    int end = 0, ans = 0;
    FOR(i, 0, n) {
        if (v[i].fs >= end) {
            end = v[i].sc;
            ans++;
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