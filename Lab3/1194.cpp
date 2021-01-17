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
 * 從n點開始dfs, 只要走到無法再走都沒有遇到環就成功，把結果記在pushed
 * 如果遇到環就拿不到，直接結束dfs
 * key:dfs
 * time:8ms
****************************************************************/

struct node {
    int id;
    vector<int> next;
} v[10001];

int r, k, n, a, b;
bool vis[10001];
bool pushed[10001];
bool loop;
vector<int> ans;

/****************************************************************
 * 由於每個點的入度最多只有1（樹的結構）
 * 所以可以把點a到點b邊的值紀錄在b點上(a, b為舉例)，源頭值為0
 * 從源頭dfs找到最大值
 * key:dfs
 * time:44ms
****************************************************************/

void dfs(int i) {
    vis[i] = true;
    for (auto k : v[i].next) {
        if (vis[k]) {
            loop = true;
            return;
        } else
            dfs(k);
    }
    if (!pushed[i]) {
        ans.pb(i);
        pushed[i] = true;
    }
    vis[i] = false;
    return;
}

void solve() {
    ans.clear();
    loop = false;
    FOR(i, 0, 10001) {
        v[i].next.clear();
        vis[i] = false;
        pushed[i] = false;
    }
    cin >> r >> k >> n;
    FOR(i, 0, k) {
        cin >> a >> b;
        v[b].next.pb(a);
    }
    dfs(n);
    if (loop)
        cout << "Lion can not pass this chapter!" << endl;
    else {
        FOR(i, 0, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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