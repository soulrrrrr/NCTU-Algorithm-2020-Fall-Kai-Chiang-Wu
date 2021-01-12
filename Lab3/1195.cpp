#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
#define pii pair<int, int>
#define int ll

struct node {
    int val;
    vector<int> next;
} v[100001];

int n, k, a, b;
int ans;

void dfs(int i, int value) {
    if (v[i].next.size() == 0) {
        ans = max(ans, value + v[i].val);
    }
    for (auto r : v[i].next) {
        dfs(r, value + v[i].val);
    }
    return;
}

void solve() {
    ans = 0;
    FOR(i, 0, 100001) {
        v[i].next.clear();
    }
    cin >> n >> k;
    FOR(i, 0, n) {
        cin >> a >> b;
        if (a != -1)
            v[a].next.pb(i);
        v[i].val = b;
    }
    dfs(k, 0);
    cout << ans << endl;
    return;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int nn;
    cin >> nn;
    FOR(i, 0, nn) {
        solve();
    }
    return 0;
}