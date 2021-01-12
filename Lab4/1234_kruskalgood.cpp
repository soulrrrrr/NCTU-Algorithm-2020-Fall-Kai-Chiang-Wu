#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int, int>
#define fs first
#define sc second
#pragma GCC optimize("O3", "unroll-loops")
//kruskal
int t, n, m, x, y, e;
int dis2;
pii nd[755];
int fa[755];

struct edge {
    int from, to;
    int val2;
    edge() {}
    edge(int from, int to, int val2) : from(from), to(to), val2(val2) {}
    bool operator<(const edge &a) {
        return val2 < a.val2;
    }
};

vector<edge> eg;
vector<pii> ans;

int find(int x) {
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void unin(int x, int y) {
    int fax = find(x), fay = find(y);
    fa[fax] = fay;
}

void init() {
    memset(nd, 0, sizeof(nd));
    eg.clear();
    ans.clear();
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

void solve() {
    cin >> n;
    e = n - 1;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> nd[i].fs >> nd[i].sc;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dis2 = (nd[i].fs - nd[j].fs) * (nd[i].fs - nd[j].fs) + (nd[i].sc - nd[j].sc) * (nd[i].sc - nd[j].sc);
            eg.pb(edge(i, j, dis2));
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        if (find(x) != find(y)) {
            unin(x, y);
            e--;
        }
    }
    sort(eg.begin(), eg.end());

    for (auto ee : eg) {
        if (e == 0)
            break;
        if (find(ee.from) != find(ee.to)) {
            unin(ee.from, ee.to);
            ans.pb({ee.from, ee.to});
            e--;
        }
    }
    cout << ans.size() << '\n';
    ;
    for (auto p : ans) {
        cout << p.fs << " " << p.sc << '\n';
    }
}

signed main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}