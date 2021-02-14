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
 * 一天最多能寫一份作業
 * 先把天數大於總作業份數的作業提出(這些一定可以完成) ---1
 * 將作業按照天sort，如果同天則由分數高s排到分數低
 * 維護一min heap，放分數(用priority_queue實作)
 * 維持heap的大小不能超過天數
 * 把---1的解加上heap內的所有值即為答案
 * key:greedy
 * time:1,172ms
****************************************************************/

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