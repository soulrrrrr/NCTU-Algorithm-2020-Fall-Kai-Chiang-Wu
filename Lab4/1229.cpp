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
 * 在做dijestra時要判斷需不需要等
 * 如果不用就正常做
 * 如果要就要加上等待的時間
 * key:dijestra
 * time:92ms
****************************************************************/

//dijestra
int cases;
int N, M, S, T;
int u, v, x, y, t;
int inf = 1e9;

struct edge {
    int to;
    int val;
    int ysec, nsec; // yes sec, no sec
    edge(int a, int b, int c, int d) : to(a), val(b), ysec(c), nsec(d) {}
};

struct node {
    vector<edge> ed;
} nd[10005];

int dist[10005];

void init() {
    FOR(i, 0, 10005) {
        dist[i] = inf;
        nd[i].ed.clear();
    }
    dist[S] = 0;
}

struct cmp {
    bool operator()(int &a, int &b) {
        return dist[a] > dist[b];
    }
};

void solve() {
    cin >> N >> M >> S >> T;
    init();
    FOR(i, 0, M) {
        cin >> u >> v >> x >> y >> t;
        nd[u].ed.pb(edge(v, t, x, y));
    }
    //dijestra
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(S);
    while (!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        for (auto e : nd[tmp].ed) {
            int t = dist[tmp] % (e.ysec + e.nsec);
            if (e.val > e.ysec) // 此情況下會永遠走不過去
                continue;
            if (t >= 0 && t <= e.ysec - e.val) { // dont need to wait
                if (dist[e.to] > dist[tmp] + e.val) {
                    dist[e.to] = dist[tmp] + e.val;
                    pq.push(e.to);
                }
            } else { //need to wait
                if (dist[e.to] > dist[tmp] + (e.ysec + e.nsec) - t + e.val) {
                    dist[e.to] = dist[tmp] + (e.ysec + e.nsec) - t + e.val;
                    pq.push(e.to);
                }
            }
        }
    }
    cout << dist[T] << '\n';
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