#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
#define pii pair<int, int>
#define int ll

int n, t1, t2;
pii p[10000 + 10]; // x, y
bool deleted[10000 + 10];
vector<pii> r; /// id1, id2
signed main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
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
            if ((p[i].fs - p[j].fs) * (p[i].fs - p[j].fs) + (p[i].sc - p[j].sc) * (p[i].sc - p[j].sc) < 40000) {
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
        if (!deleted[r[i].fs] && !deleted[r[i].sc]) {
            deleted[r[i].fs] = true;
            removed++;
        }
    }
    cout << "Number of removed 7-11 stores: " << removed << endl;
    return 0;
}