#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define fs first
#define second sc
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)

/****************************************************************
 * 把每一列的第一個數字取出來
 * 找到第一個數字小於等於該數字的那列，線性搜索到值
 * key:brute force
 * time:O(m+n)
****************************************************************/

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> v(m, vector<int>(n, 0));
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> v[i][j];
        }
    }
    vector<int> firstCol;
    FOR(i, 0, m) {
        firstCol.pb(v[i][0]);
    }
    FOR(r, 0, k) { // solve
        int target;
        cin >> target;
        int i = 0, j = 0;
        if (target < v[i][j] || target > v[m - 1][n - 1]) {
            cout << -1 << endl;
            continue;
        } else {
            while (i != m) {
                if (target >= v[i][j])
                    i++;
                else
                    break;
            }
            i--;
            //cout << i << endl;
            while (j != n) {
                if (target == v[i][j]) {
                    cout << i << " " << j << endl;
                    break;
                }
                j++;
            }
        }
        if (j == n)
            cout << -1 << endl;
    }
    return 0;
}