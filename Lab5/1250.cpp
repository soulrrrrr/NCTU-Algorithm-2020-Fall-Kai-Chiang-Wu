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

struct node {
    int x, y;
} v[10005];
int cases, n;

void solve() {
    int ans = 0;
    cin >> n;
    FOR(i, 0, n) {
        cin >> v[i].x >> v[i].y;
    }
    sort(v, v + n, [](node &a, node &b) { return (a.x - a.y) < (b.x - b.y); });
    FOR(i, 0, n / 2) {
        ans += v[i].x;
    }
    FOR(i, n / 2, n) {
        ans += v[i].y;
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