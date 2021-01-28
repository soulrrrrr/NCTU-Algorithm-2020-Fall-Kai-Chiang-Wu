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
 * 把prebuilt的邊先union
 * 再對剩下的邊做kruskal
 * key:並查集, union find, kruskal
 * time:104ms
****************************************************************/
//kruskal
int t, n, m, x, y, e;
int dis2;    // dis平方
pii nd[755]; // nodes
int fa[755]; // father

struct edge {
    int from, to;
    int val2; //val平方
    edge() {}
    edge(int from, int to, int val2) : from(from), to(to), val2(val2) {}
    bool operator<(const edge &a) const {
        return val2 < a.val2;
    }
};

vector<edge> eg;
vector<pii> ans;

int find(int x) {
    if (x != fa[x])
        fa[x] = find(fa[x]); //路徑壓縮
    return fa[x];
}

void unin(int x, int y) {             // union
    int fax = find(x), fay = find(y); //father of x, father of y
    fa[fax] = fay;
}

void init() { // initialize
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