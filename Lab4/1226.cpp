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

int cases, n, r, S, B;
int a, b, c;
int inf = 1000000000;

struct node {
    vector<pair<int, int>> e;
    int pre;
    int dis;
} v[20005];

struct cmp {
    bool operator()(int &a, int &b) {
        return v[a].dis > v[b].dis;
    }
};

void solve() {
    FOR(i, 0, 20005) {
        v[i].e.clear();
        v[i].pre = 0;
        v[i].dis = 0;
    }
    priority_queue<int, vector<int>, cmp> pq; //dijestra
    cin >> n >> r >> S >> B;
    FOR(i, 0, n) {
        v[i].dis = inf;
        v[i].pre = -1;
    }
    v[S].dis = 0;
    pq.push(S);
    FOR(i, 0, r) {
        cin >> a >> b >> c;
        v[a].e.pb({b, c});
        v[b].e.pb({a, c});
    }
    while (pq.size()) {
        int temp = pq.top();
        pq.pop();
        for (auto i : v[temp].e) {
            if (v[i.fs].dis > v[temp].dis + i.sc) {
                v[i.fs].dis = v[temp].dis + i.sc;
                v[i.fs].pre = temp;
                pq.push(i.fs);
            }
        }
    }
    if (v[B].dis >= 1000000000 || v[B].pre == -1)
        cout << "YOU DIED"
             << "\n";
    else
        cout << v[B].dis << "\n";
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