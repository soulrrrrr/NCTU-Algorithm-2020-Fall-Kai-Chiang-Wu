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
 * v[i] 紀錄i可以走到的牌的號碼
 * 從起點bfs，有遇到0就輸出possible的那串並return
 * 跑完都沒有就輸出impossible的那串
 * key:bfs
 * time: 8ms
****************************************************************/

int m, n, start_i;
int temp;

void solve() {
    cin >> n >> start_i;
    pii v[n];
    bool vis[n];
    FOR(i, 0, n) {
        cin >> temp;
        v[i] = {i - temp, i + temp};
        vis[i] = false;
    }
    queue<int> q;
    q.push(start_i);
    while (q.size()) {
        temp = q.front();
        q.pop();
        vis[temp] = true;
        if (v[temp].fs == v[temp].sc) { // zero
            cout << "We will watch your career with great interest." << endl;
            return;
        }
        if (v[temp].fs >= 0 && !vis[v[temp].fs])
            q.push(v[temp].fs);
        if (v[temp].sc < n && !vis[v[temp].sc])
            q.push(v[temp].sc);
    }
    cout << "My disappointment is immeasurable, and my day is ruined." << endl;
    return;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> m;
    FOR(i, 0, m) {
        solve();
    }

    return 0;
}