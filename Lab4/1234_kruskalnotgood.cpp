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

struct edge {
    int from, to;
    int val;
    edge() {}
    edge(int from, int to, int val) : from(from), to(to), val(val) {}
    bool operator<(const edge &a) const {
        return val > a.val; // 邪教寫法
    }
};

pii nodes[750 + 5];
int fa[750 + 5];
priority_queue<edge> pq;

int t, n, m, a, b;

int dis(int i, int j) {
    return (nodes[i].fs - nodes[j].fs) * (nodes[i].fs - nodes[j].fs) + (nodes[i].sc - nodes[j].sc) * (nodes[i].sc - nodes[j].sc);
}

void init() {
    memset(nodes, 0, sizeof(nodes));
    memset(fa, 0, sizeof(fa));
    FOR(i, 1, n + 1) {
        fa[i] = i;
    }
    while (!pq.empty())
        pq.pop();
    return;
}

int find(int i) {   //找祖先
    if (i != fa[i]) //如果i不是祖先 就往上找 路徑壓縮
        fa[i] = find(fa[i]);
    return fa[i];
}

void solve() {
    cin >> n;
    init();
    FOR(i, 1, n + 1) {
        cin >> nodes[i].fs >> nodes[i].sc;
    }
    FOR(i, 1, n + 1) {
        FOR(j, i + 1, n + 1) {
            pq.push(edge(i, j, dis(i, j)));
        }
    }
    cin >> m;
    vector<pii> ans;
    int sz;
    FOR(i, 0, m) {
        cin >> a >> b;
        int faA = find(a), faB = find(b);
        if (faA != faB) {
            fa[faA] = faB;
            sz++;
        }
    }
    int e = n - 1 - sz;
    while (!pq.empty() && e) {
        edge eg = pq.top();
        //cout << eg.val << " ";
        pq.pop();
        int faA = find(eg.from), faB = find(eg.to);
        if (faA != faB) {
            fa[faA] = faB;
            e--;
            ans.pb({eg.from, eg.to});
        }
    }
    e = ans.size();
    cout << e << endl;
    FOR(i, 0, ans.size()) {
        cout << ans[i].fs << " " << ans[i].sc << endl;
    }
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}