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

int cases, n, d, s;
vector<pii> v;

void solve() {
    int ans = 0;
    v.clear();
    cin >> n;
    FOR(i, 0, n) {
        cin >> d >> s;
        if (d > n)
            ans += s;
        else
            v.pb({d, s});
    }
    sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.fs < b.fs || a.fs == b.fs && a.sc > b.sc; });
    priority_queue<int, vector<int>, greater<int>> pq;
    FOR(i, 0, v.size()) {
        if (pq.size() < v[i].fs)
            pq.push(v[i].sc);
        else if (v[i].sc > pq.top()) {
            pq.pop();
            pq.push(v[i].sc);
        }
    }
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';
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