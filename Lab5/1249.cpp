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
 * key:greedy
****************************************************************/

int cases, n;
string a, b;
char A[500005], B[500005], ans[500005];

void solve() {
    cin >> a >> b;
    n = a.size();
    strcpy(A, a.c_str());
    strcpy(B, b.c_str());
    sort(A, A + n);
    sort(B, B + n);
    int aHead = 0, aTail = (n - 1) / 2, bHead = (n + 1) / 2, bTail = n - 1;
    int oHead = 0, oTail = n - 1;
    int turn = 1;
    int a_put = (n + 1) / 2, b_put = n - a_put;
    FOR(i, 0, n) {
        if (A[aHead] >= B[bTail]) {
            if (turn == 1) { //a
                if (a_put == b_put) {
                    FOR(j, 0, a_put) {
                        ans[oHead++] = B[bTail--];
                        ans[oHead++] = A[aHead++];
                    }
                } else {
                    ans[oHead++] = A[aHead++];
                    FOR(j, 0, b_put) {
                        ans[oHead++] = B[bTail--];
                        ans[oHead++] = A[aHead++];
                    }
                }
            } else { // b
                if (a_put == b_put) {
                    FOR(j, 0, b_put) {
                        ans[oHead++] = A[aHead++];
                        ans[oHead++] = B[bTail--];
                    }
                } else {
                    ans[oHead++] = B[bTail--];
                    FOR(j, 0, a_put) {
                        ans[oHead++] = A[aHead++];
                        ans[oHead++] = B[bTail--];
                    }
                }
            }
            break;
        }
        if (turn == 1) {
            ans[oHead++] = A[aHead++];
            a_put--;
            turn = 2;
        } else {
            ans[oHead++] = B[bTail--];
            b_put--;
            turn = 1;
        }
    }
    FOR(i, 0, n) {
        cout << ans[i];
    }
    cout << '\n';
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