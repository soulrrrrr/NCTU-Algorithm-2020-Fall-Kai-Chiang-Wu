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

int n;
string m;
int a, b, k;
char c;

struct edge {
    int from, to;
    int val;
    edge() {}
    edge(int from, int to, int val) : from(from), to(to), val(val) {}
};
vector<edge> eg;

int dis[105];

void solve() {
    int t = stoi(m);
    memset(dis, 0, sizeof(dis));
    eg.clear();
    FOR(i, 1, t + 1) {
        cin >> a >> b >> c >> k;
        if (c == '<') {
            eg.pb(edge(a - 1, a + b, k - 1)); //why a-1?
        } else if (c == '>') {
            eg.pb(edge(a + b, a - 1, -k - 1));
        }
    }
    FOR(i, 0, n + 1) {
        eg.pb(edge(n + 1, i, 0)); //n+1 is fake source
    }
    //bellman_ford
    dis[n + 1] = 0;
    FOR(i, 0, n + 1) {
        dis[i] = LLONG_MAX / 3;
    }
    FOR(tt, 0, n + 1) {
        for (auto e : eg) {
            if (dis[e.from] + e.val < dis[e.to]) {
                dis[e.to] = dis[e.from] + e.val;
            }
        }
    }
    bool flag = false;
    for (auto e : eg) {
        if (dis[e.from] + e.val < dis[e.to]) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "There is no bus in Gensokyo." << endl;
        return;
    }
    cout << "All aboard the hype bus choo choo." << endl;
    return;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (true) {
        cin >> n >> m;
        if (m == "BAKA")
            break;
        solve();
    }
    return 0;
}