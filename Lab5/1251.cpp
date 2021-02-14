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

int v[7];

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (cin >> v[1] >> v[2] >> v[3] >> v[4] >> v[5] >> v[6]) {
        if (v[1] + v[2] + v[3] + v[4] + v[5] + v[6] == 0)
            return 0;
        int ans = 0;
        int left1 = 0, left2 = 0;

        ans += v[6];
        v[6] = 0;

        ans += v[5];
        left1 += v[5] * 11;
        v[5] = 0;

        ans += v[4];
        left2 += v[4] * 5;
        v[4] = 0;

        ans += v[3] / 4;
        v[3] %= 4;

        if (v[3] != 0) {
            ans += 1;
            if (v[3] == 1) {
                left2 += 5;
                left1 += 7;
            } else if (v[3] == 2) {
                left2 += 3;
                left1 += 6;
            } else if (v[3] == 3) {
                left2 += 1;
                left1 += 5;
            }
            v[3] = 0;
        }

        v[2] -= left2;
        if (v[2] > 0) {
            ans += v[2] / 9;
            v[2] %= 9;
            if (v[2] != 0) {
                ans += 1;
                left1 += 36 - v[2] * 4;
            }
        } else {
            left1 += 4 * (-v[2]);
        }

        v[1] -= left1;
        if (v[1] > 0) {
            ans += v[1] / 36;
            v[1] %= 36;
            if (v[1] != 0)
                ans += 1;
        }

        cout << ans << '\n';
    }
    return 0;
}