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
 * 假設出現的最小邊為eg[0], eg[1], ..., eg[m-1]
 * 當最大邊減最小邊之值比原本大時就更新
 * key:並查集, union find, kruskal
 * time:16ms
****************************************************************/

struct edge {
    int from, to;
    int val;
    bool operator<(const edge &a) const {
        return val < a.val;
    }
} eg[10005];

int cases, n, m;
int now_min, now_max;

int siz[105];
int fa[105];

int find(int i) {
    if (fa[i] != i)
        fa[i] = find(fa[i]);
    return fa[i];
}

void unin(int a, int b) {
    int faA = find(a), faB = find(b);
    if (faA == faB)
        return;
    if (siz[faA] > siz[faB])
        swap(faA, faB);
    fa[faA] = faB;
    siz[faB] += siz[faA];
}

bool kruskal(int k) {
    FOR(i, 1, n + 1) {
        fa[i] = i;
    }
    FOR(i, 1, n + 1) {
        siz[i] = 1;
    }
    int e = n - 1;
    while (k < m && e > 0) {
        //cout << e;
        edge temp = eg[k];
        int faA = find(temp.from), faB = find(temp.to);
        if (faA != faB) {
            if (e == n - 1) {
                now_min = temp.val;
            }
            if (e == 1) {
                now_max = temp.val;
            }
            unin(temp.from, temp.to);
            e--;
        }
        k++;
    }
    //cout << endl;
    if (e == 0)
        return true;
    else
        return false;
}

void init() {
    memset(eg, 0, sizeof(eg));
    FOR(i, 0, 105) {
        fa[i] = i;
    }
    FOR(i, 0, 105) {
        siz[i] = 1;
    }
}

void solve() {
    init();
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> eg[i].from >> eg[i].to >> eg[i].val;
    }
    int ans = INT_MAX;
    sort(eg, eg + m);
    FOR(i, 0, m) {
        if (kruskal(i))
            ans = min(ans, now_max - now_min);
        else
            break;
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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