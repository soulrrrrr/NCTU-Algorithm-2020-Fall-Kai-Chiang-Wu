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
 * 從S開始找最短路徑
 * 如果pre[B] = -1 表示沒有辦法從S走到B
 * key:bellman-ford
 * time:1,160ms
****************************************************************/

int cases;
int s, w, f, t, val;
int inf = 1e9;

struct edge {
    int from, to;
    int val;
    edge() {}
    edge(int from, int to, int val) : from(from), to(to), val(val) {}
} eg[2005];

int dist[1005];

void solve() {
    cin >> s >> w;
    bool flag = false;
    dist[0] = 0;
    FOR(i, 1, s + 1) {
        dist[i] = inf;
    }
    FOR(i, 0, w) {
        cin >> f >> t >> val;
        eg[i] = edge(f, t, val);
    }
    FOR(i, 0, s) {
        FOR(j, 0, w) {
            if (dist[eg[j].to] > dist[eg[j].from] + eg[j].val) {
                dist[eg[j].to] = dist[eg[j].from] + eg[j].val;
            }
        }
    }
    FOR(j, 0, w) {
        if (dist[eg[j].to] > dist[eg[j].from] + eg[j].val) { //做了n-1次relax還可以relax，表示有負環
            flag = true;
            break;
        }
    }
    cout << (flag ? "This is the choice of Steins;Gate" : "El Psy Kongroo") << '\n';
    return;
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