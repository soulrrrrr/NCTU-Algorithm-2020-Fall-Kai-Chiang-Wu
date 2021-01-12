#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)

int n, r, c, ans = 0;
bool walked[64][64];
int mp[64][64]; //B:0, L:1, T:2

void dfs(int a, int b, int type) { // 0:horizontal, 1:vertical
    if (a < 0 || a >= r || b < 0 || b >= c || walked[a][b] || mp[a][b] == 0)
        return;
    if (a == r - 1 && b == c - 1) {
        ans++;
        return;
    }
    walked[a][b] = true;
    if (type == 0 && mp[a][b] == 1) {
        dfs(a, b + 1, 0);
        dfs(a, b - 1, 0);
    }
    if (type == 0 && mp[a][b] == 2) {
        dfs(a + 1, b, 1);
        dfs(a - 1, b, 1);
    }
    if (type == 1 && mp[a][b] == 1) {
        dfs(a + 1, b, 1);
        dfs(a - 1, b, 1);
    }
    if (type == 1 && mp[a][b] == 2) {
        dfs(a, b + 1, 0);
        dfs(a, b - 1, 0);
    }
    walked[a][b] = false;
    return;
}

signed main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n;
    while (n--) {
        ans = 0;
        memset(walked, false, sizeof(walked));
        memset(mp, 0, sizeof(mp));
        cin >> r >> c;
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                char t;
                cin >> t;
                if (t == 'B')
                    mp[i][j] = 0;
                else if (t == 'L')
                    mp[i][j] = 1;
                else
                    mp[i][j] = 2;
            }
        }
        if (mp[0][0] != 0) {
            walked[0][0] = true;
            dfs(0, 1, 0);
            dfs(1, 0, 1);
            walked[0][0] = false;
        }
        cout << "Number of legal solutions: " << ans << endl;
    }
    return 0;
}