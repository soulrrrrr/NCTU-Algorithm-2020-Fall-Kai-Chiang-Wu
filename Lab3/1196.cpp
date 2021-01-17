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

/****************************************************************
 * 用kosaraju找scc並縮點(建新圖，將同個scc的所有點變成一個點)
 * 縮點的同時記錄入度
 * 答案為入度為0的點的總和
 * key:scc, (kosaraju, tarjan, topological sort)
 * time:44ms
****************************************************************/

vector<int> nodes[10001], noder[10001], scc[10001];

int e, v, ans, temp, tot;
int vis[10001];
stack<int> s;

void init() {
    while (s.size()) {
        s.pop();
    }
    ans = 0;
    tot = 0;
    FOR(i, 0, 10001) {
        nodes[i].clear();
        noder[i].clear();
        scc[i].clear();
        vis[i] = 0;
    }
    return;
}

void init_vis() {
    FOR(i, 0, 10001) {
        vis[i] = 0;
    }
}

void dfs(int i) {
    //cout << "i:" << i << endl;
    vis[i] = true;
    for (auto k : nodes[i]) {
        if (!vis[k])
            dfs(k);
    }
    s.push(i);
    return;
}

void rdfs(int i, int id) {
    //cout << "i:" << i << endl;
    vis[i] = id;
    for (auto k : noder[i]) {
        if (!vis[k])
            rdfs(k, id);
    }
    return;
}

void solve() {
    init();
    int a, b;
    cin >> e >> v;
    FOR(i, 0, v) {
        cin >> a >> b;
        nodes[a - 1].pb(b - 1);
        noder[b - 1].pb(a - 1);
    }
    FOR(i, 0, e) {
        if (!vis[i])
            dfs(i);
    }
    init_vis();
    int cnt = 1;
    FOR(i, 0, e) {
        temp = s.top();
        s.pop();
        if (!vis[temp]) {
            rdfs(temp, cnt);
            cnt++;
        }
    }
    int indegree[10001];
    FOR(i, 0, 10001) {
        indegree[i] = 0;
    }
    FOR(i, 0, e) { // build scc graph
        //cout << vis[i] << " ";
        for (auto k : nodes[i]) {
            if (vis[i] != vis[k]) {
                scc[vis[i]].pb(vis[k]);
                indegree[vis[k]]++;
            }
        }
    }
    int ind = 0;
    FOR(i, 1, cnt) {
        if (!indegree[i])
            ind++;
    }
    cout << ind << endl;
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