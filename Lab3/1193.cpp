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
#define N 210

/****************************************************************
 * 這題
 * 很難
 * 判斷p的條件為如果y跟n都可就是p
 * key: 2-sat, (kosaraju, tarjan, scc)
 * time:20ms
****************************************************************/

vector<int> G[N], Gt[N], Gscc[N];

int n, m, k;
int ans, temp, tot;
int vis[N], comp[N];
stack<int> s;
string ss;

void init() {
    while (s.size()) {
        s.pop();
    }
    ans = 0;
    tot = 0;
    FOR(i, 0, N) {
        G[i].clear();
        Gt[i].clear();
        Gscc[i].clear();
        vis[i] = 0;
        comp[i] = 0;
    }
    return;
}

void init_vis() {
    FOR(i, 0, N) {
        vis[i] = 0;
    }
}

void dfs(int i) {
    //cout << "i:" << i << endl;
    vis[i] = true;
    for (auto k : G[i]) {
        if (!vis[k])
            dfs(k);
    }
    s.push(i);
    return;
}

void rdfs(int i, int id) { //reverse dfs
    //cout << "i:" << i << endl;
    comp[i] = id;
    for (auto k : Gt[i]) {
        if (!comp[k])
            rdfs(k, id);
    }
    return;
}

void dfsc(int i) { // normal dfs
    //cout << "i:" << i << endl;
    vis[i] = true;
    for (auto k : G[i]) {
        if (!vis[k]) {
            //cout << k;
            dfsc(k);
        }
    }
    //cout << "I:" << i << endl;
    return;
}

void add(int u, int v) {
    if (find(G[u].begin(), G[u].end(), v) == G[u].end())
        G[u].pb(v);
    if (find(Gt[v].begin(), Gt[v].end(), v) == Gt[v].end())
        Gt[v].pb(u);
    return;
}

void solve() {
    init();
    int a, b;
    pii p[4];
    FOR(i, 0, m) {
        cin >> k;
        FOR(j, 0, k) {
            cin >> p[j].fs >> ss, p[j].sc = (ss != "aye"); // 1~n 是true點，n+1~2n是false點
        }
        if (k >= 3) {
            FOR(j, 0, k) {
                FOR(q, j + 1, k) {
                    a = p[j].fs + n * p[j].sc;
                    b = p[q].fs + n * p[q].sc;
                    add(((a > n) ? (a - n) : (a + n)), b); //若前面不符合則後面必須符合
                    add(((b > n) ? (b - n) : (b + n)), a);
                }
            }
        } else {
            FOR(j, 0, k) {
                a = p[j].fs + n * p[j].sc;
                add(((a > n) ? (a - n) : (a + n)), a); //a若不符合就gg了，所以建a不符合到a符合的邊
            }
        }
    }
    // kosaraju
    FOR(i, 1, 2 * n + 1) {
        if (!vis[i])
            dfs(i);
    }
    int cnt = 1;
    FOR(i, 1, 2 * n + 1) {
        temp = s.top();
        s.pop();
        //vis[temp] = i;
        //cout << temp << " ";
        if (!comp[temp]) {
            rdfs(temp, cnt);
            cnt++;
        }
    }
    // kosaraju end

    FOR(i, 1, n + 1) {
        if (comp[i] == comp[i + n]) {
            cout << "It's treason, then." << endl;
            return;
        }
    }
    FOR(i, 1, n + 1) {
        init_vis();
        dfsc(i);
        bool walk_i = vis[i + n];
        init_vis();
        dfsc(i + n);
        bool walk_ni = vis[i];
        if (comp[i] < comp[i + n] && walk_i)
            cout << "n";
        else if (comp[i] > comp[i + n] && walk_ni)
            cout << "y";
        else
            cout << "p";
    }
    cout << endl;
    return;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve();
    }
    return 0;
}