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
#define N 210

vector<int> G[N], Gt[N], Gscc[N];

int n, m, k;
int ans, temp, tot;
int vis[N], comp[N];
stack<int> s;

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
//kosaraju
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

void rdfs(int i, int id) {
    //cout << "i:" << i << endl;
    comp[i] = id;
    for (auto k : Gt[i]) {
        if (!comp[k])
            rdfs(k, id);
    }
    return;
}
//kosaraju
void dfsc(int i) {
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
    int t1, t2, t3, t4, nt1, nt2, nt3, nt4;
    int r1, r2, r3, r4, nr1, nr2, nr3, nr4;
    string s1, s2, s3, s4;
    int a, b;
    FOR(i, 0, m) {
        cin >> k;
        if (k == 4) {
            cin >> t1 >> s1 >> t2 >> s2 >> t3 >> s3 >> t4 >> s4;
            nt1 = t1 + n, nt2 = t2 + n, nt3 = t3 + n, nt4 = t4 + n;
            if (s1 == "aye") { // no 1
                if (s2 == "aye")
                    add(nt1, t2);
                else
                    add(nt1, nt2);
                if (s3 == "aye")
                    add(nt1, t3);
                else
                    add(nt1, nt3);
                if (s4 == "aye")
                    add(nt1, t4);
                else
                    add(nt1, nt4);
            } else {
                if (s2 == "aye")
                    add(t1, t2);
                else
                    add(t1, nt2);
                if (s3 == "aye")
                    add(t1, t3);
                else
                    add(t1, nt3);
                if (s4 == "aye")
                    add(t1, t4);
                else
                    add(t1, nt4);
            }
            if (s2 == "aye") { // no 2
                if (s1 == "aye")
                    add(nt2, t1);
                else
                    add(nt2, nt1);
                if (s3 == "aye")
                    add(nt2, t3);
                else
                    add(nt2, nt3);
                if (s4 == "aye")
                    add(nt2, t4);
                else
                    add(nt2, nt4);
            } else {
                if (s1 == "aye")
                    add(t2, t1);
                else
                    add(t2, nt1);
                if (s3 == "aye")
                    add(t2, t3);
                else
                    add(t2, nt3);
                if (s4 == "aye")
                    add(t2, t4);
                else
                    add(t2, nt4);
            }
            if (s3 == "aye") { // no 3
                if (s1 == "aye")
                    add(nt3, t1);
                else
                    add(nt3, nt1);
                if (s2 == "aye")
                    add(nt3, t2);
                else
                    add(nt3, nt2);
                if (s4 == "aye")
                    add(nt3, t4);
                else
                    add(nt3, nt4);
            } else {
                if (s1 == "aye")
                    add(t3, t1);
                else
                    add(t3, nt1);
                if (s2 == "aye")
                    add(t3, t2);
                else
                    add(t3, nt2);
                if (s4 == "aye")
                    add(t3, t4);
                else
                    add(t3, nt4);
            }
            if (s4 == "aye") { // no 4
                if (s1 == "aye")
                    add(nt4, t1);
                else
                    add(nt4, nt1);
                if (s2 == "aye")
                    add(nt4, t2);
                else
                    add(nt4, nt2);
                if (s3 == "aye")
                    add(nt4, t3);
                else
                    add(nt4, nt3);
            } else {
                if (s1 == "aye")
                    add(t4, t1);
                else
                    add(t4, nt1);
                if (s2 == "aye")
                    add(t4, t2);
                else
                    add(t4, nt2);
                if (s3 == "aye")
                    add(t4, t3);
                else
                    add(t4, nt3);
            }
        } else if (k == 3) {
            cin >> t1 >> s1 >> t2 >> s2 >> t3 >> s3;
            nt1 = t1 + n, nt2 = t2 + n, nt3 = t3 + n;
            if (s1 == "aye") { // no 1
                if (s2 == "aye")
                    add(nt1, t2);
                else
                    add(nt1, nt2);
                if (s3 == "aye")
                    add(nt1, t3);
                else
                    add(nt1, nt3);
            } else {
                if (s2 == "aye")
                    add(t1, t2);
                else
                    add(t1, nt2);
                if (s3 == "aye")
                    add(t1, t3);
                else
                    add(t1, nt3);
            }
            if (s2 == "aye") { // no 2
                if (s1 == "aye")
                    add(nt2, t1);
                else
                    add(nt2, nt1);
                if (s3 == "aye")
                    add(nt2, t3);
                else
                    add(nt2, nt3);
            } else {
                if (s1 == "aye")
                    add(t2, t1);
                else
                    add(t2, nt1);
                if (s3 == "aye")
                    add(t2, t3);
                else
                    add(t2, nt3);
            }
            if (s3 == "aye") { // no 3
                if (s1 == "aye")
                    add(nt3, t1);
                else
                    add(nt3, nt1);
                if (s2 == "aye")
                    add(nt3, t2);
                else
                    add(nt3, nt2);
            } else {
                if (s1 == "aye")
                    add(t3, t1);
                else
                    add(t3, nt1);
                if (s2 == "aye")
                    add(t3, t2);
                else
                    add(t3, nt2);
            }
        } else if (k == 2) {
            cin >> t1 >> s1 >> t2 >> s2;
            nt1 = t1 + n, nt2 = t2 + n;
            if (s1 == "aye") { // yes 1
                if (s2 == "aye") {
                    add(t1, t2);
                    add(t2, t1);
                    add(nt1, nt2);
                    add(nt2, nt1);
                    add(nt1, t1);
                    add(nt2, t2);
                } else {
                    add(t1, nt2);
                    add(nt2, t1);
                    add(nt1, t2);
                    add(t2, nt1);
                    add(nt1, t1);
                    add(t2, nt2);
                }
            } else { // no 1
                if (s2 == "aye") {
                    add(nt1, t2);
                    add(nt2, t1);
                    add(t1, nt2);
                    add(t2, nt1);
                    add(t1, nt1);
                    add(nt2, t2);
                } else {
                    add(nt1, nt2);
                    add(nt2, nt1);
                    add(t1, t2);
                    add(t2, t1);
                    add(t1, nt1);
                    add(t2, nt2);
                }
            }
        } else if (k == 1) {
            cin >> t1 >> s1;
            nt1 = t1 + n;
            if (s1 == "aye")
                add(nt1, t1);
            else
                add(t1, nt1);
        }
    }
    /*
    FOR(i, 1, 2 * n + 1) {
        for (auto k : G[i]) {
            cout << k << " ";
        }
        cout << endl;
    }*/
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
    /*cout << endl;
    FOR(i, 1, 2 * n + 1) {
        cout << comp[i] << " ";
    }*/
    // kosaraju end

    /*FOR(i, 1, 2 * n + 1) { // build scc graph
        //cout << i;
        for (auto k : G[i]) {
            if (comp[i] != comp[k]) {
                Gscc[comp[i]].pb(comp[k]);
            }
        }
    }*/
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