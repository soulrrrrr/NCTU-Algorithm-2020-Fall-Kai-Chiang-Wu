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

int cases, n, w, p, m, temp, u, v, c;

int G[105][105];
bool vis[105][105];
int level[105];

int dfs(int u, int t, int f) { //u是開始
    if (u == t)
        return f;
    FOR(i, 0, t + 1) { //偷吃步 s永遠是0 應該要用s
        if (level[u] < level[i] && G[u][i] > 0) {
            int flow = dfs(i, t, min(f, G[u][i]));
            if (flow > 0) {
                G[u][i] -= flow;
                G[i][u] += flow;
                //cout << flow;
                return flow;
            }
        }
    }
    return 0;
}

void bfs(int s, int t) {
    FOR(i, s, t + 1) {
        level[i] = -1;
    } // source的level為0
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        FOR(i, s, t + 1) {
            if (level[i] < 0 && G[u][i] > 0) {
                level[i] = level[u] + 1;
                q.push(i);
            }
        }
    }
}

int dinic(int s, int t) {
    int max_flow = 0, aug_flow;
    int a = 0;
    while (true) {
        bfs(s, t);
        memset(vis, 0, sizeof(vis));
        if (level[t] < 0) //level沒有被更新到 表示走不到
            break;
        while ((aug_flow = dfs(s, t, INT_MAX)) > 0)
            max_flow += aug_flow;
        //cout << max_flow << " ";
    }
    return max_flow;
}

void solve() {
    memset(G, 0, sizeof(G));
    cin >> n >> w >> p >> m;
    int s = 0, t = n + 1;
    FOR(i, 0, p) {
        cin >> temp;
        G[s][temp] = INT_MAX;
    }
    FOR(i, 0, m) {
        cin >> temp;
        G[temp][t] = INT_MAX;
    }
    FOR(i, 0, w) {
        cin >> u >> v >> c;
        G[u][v] = c;
    }
    cout << dinic(s, t) << '\n';
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