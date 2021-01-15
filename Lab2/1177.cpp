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
 * 先依離中心遠近sort
 * 再將要移除的點對依點對距離sort
 * key:brute force
 * time: O(n2) 32ms
****************************************************************/

int n, t1, t2;
pii p[10000 + 10]; // x, y
bool deleted[10000 + 10];
vector<pii> r; /// id1, id2
signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, 0, n) {
        cin >> t1 >> t2;
        p[i] = {t1, t2};
    }
    sort(p, p + n, [](pii a, pii b) {
        return (a.fs - 20000) * (a.fs - 20000) + (a.sc - 20000) * (a.sc - 20000) < (b.fs - 20000) * (b.fs - 20000) + (b.sc - 20000) * (b.sc - 20000);
    });
    int removed = 0;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            if ((p[i].fs - p[j].fs) * (p[i].fs - p[j].fs) + (p[i].sc - p[j].sc) * (p[i].sc - p[j].sc) < 40000) { // 200 * 200 = 40000
                r.pb({i, j});
            }
        }
    }
    sort(r.begin(), r.end(), [](pii a, pii b) {
        int x1 = p[a.fs].fs - p[a.sc].fs;
        int y1 = p[a.fs].sc - p[a.sc].sc;
        int x2 = p[b.fs].fs - p[b.sc].fs;
        int y2 = p[b.fs].sc - p[b.sc].sc;
        return (x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2);
    });
    FOR(i, 0, r.size()) {
        if (!deleted[r[i].fs] && !deleted[r[i].sc]) { //若其中一間已被刪除，另一間就不用刪
            deleted[r[i].fs] = true;
            removed++;
        }
    }
    cout << "Number of removed 7-11 stores: " << removed << endl;
    return 0;
}