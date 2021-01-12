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

int cases, n, m, k, a, b, s, t, ans;

int G[205][205];
int prv[205];

int findflow() {
    int now = t;
    int flow = INT_MAX;
    while (now != s) {
        flow = min(flow, G[prv[now]][now]);
        now = prv[now];
    }
    now = t;
    while (now != s) {
        G[prv[now]][now] -= flow;
        G[now][prv[now]] += flow;
        now = prv[now];
    }
    return flow;
}

int bfs() {
    memset(prv, -1, sizeof(prv));
    queue<int> q;
    q.push(s);
    prv[s] = s;
    int tp;
    while (!q.empty()) {
        tp = q.front();
        q.pop();
        if (tp == t)
            break;
        FOR(i, 0, t + 1) {
            if (i == s)
                continue;
            if (G[tp][i] > 0 && prv[i] == -1) {
                prv[i] = tp;
                q.push(i);
                //cout << i << " s";
            }
        }
    }
    if (tp != t)
        return 0;
    int rr = findflow();
    //cout << findflow();
    return rr;
}

void solve() {
    cin >> n >> m >> k;
    s = n + m, t = s + 1;
    memset(G, 0, sizeof(G));
    FOR(i, 0, k) {
        cin >> a >> b;
        G[a][n + b] = 1;
        G[s][a] = 1;
        G[n + b][t] = 1;
    }
    /*FOR(i, 0, t + 1) {
        FOR(j, 0, t + 1) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }*/
    ans = 0;
    int flow;
    while ((flow = bfs()) > 0) {
        ans += flow;
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