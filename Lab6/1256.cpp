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
int v[1005];
int lis[1005];
int rlis[1005];
bool flag;

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> v[i];
    }
    int from, to;
    vector<int> incr;
    incr.pb(v[0]);
    lis[0] = 1;
    FOR(i, 1, n) {
        if (v[i] > incr.back()) {
            incr.pb(v[i]);
        } else {
            *lower_bound(incr.begin(), incr.end(), v[i]) = v[i];
        }
        lis[i] = incr.size();
    }

    vector<int> decr;
    decr.pb(v[n - 1]);
    rlis[n - 1] = 1;
    REF(i, n - 2, 0) {
        if (v[i] > decr.back()) {
            decr.pb(v[i]);
        } else {
            *lower_bound(decr.begin(), decr.end(), v[i]) = v[i];
        }
        rlis[i] = decr.size();
    }
    int mx = 0;
    FOR(i, 0, n) {
        if (lis[i] == 1 || rlis[i] == 1)
            continue;
        mx = max(mx, lis[i] + rlis[i] - 1);
    }
    cout << (n - mx) << '\n';
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