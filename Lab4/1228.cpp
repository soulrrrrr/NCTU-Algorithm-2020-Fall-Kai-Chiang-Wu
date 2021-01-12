#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define int ll
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
#define pii pair<int, int>
//bellman-ford
int cases;
int s, w, f, t, val;
int inf = 10e9;

struct edge {
    int from, to;
    int val;
    edge() {}
    edge(int from, int to, int val) : from(from), to(to), val(val) {}
} eg[2005];

int dist[1005];

void solve() {
    bool flag = false;
    dist[0] = 0;
    FOR(i, 1, 1005) {
        dist[i] = inf;
    }
    cin >> s >> w;
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
        if (dist[eg[j].to] > dist[eg[j].from] + eg[j].val) {
            dist[eg[j].to] = -inf;
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