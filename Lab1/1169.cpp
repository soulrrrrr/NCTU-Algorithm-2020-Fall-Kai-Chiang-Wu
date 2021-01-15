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
 * 把第二列沒有出現過的數字放進map
 * 再看第一列，有出現在map的就紀錄，沒有的就放進vector
 * 把vector sort
 * 先輸出紀錄次數的vector再輸出紀錄沒有的vector
 * key:greedy
 * time:O(nlogn)
****************************************************************/

int main() {
    int ncases;
    cin >> ncases;
    FOR(i, 0, ncases) {
        int n, m;
        cin >> n >> m;
        vector<int> v1, v2;
        map<int, int> mp;
        int temp;
        FOR(i, 0, n) {
            cin >> temp;
            v1.pb(temp);
        }
        FOR(i, 0, m) {
            cin >> temp;
            v2.pb(temp);
            mp[temp] = 0;
        }
        vector<int> sorted;
        FOR(i, 0, n) {
            if (mp.find(v1[i]) != mp.end()) {
                mp[v1[i]] = mp[v1[i]] + 1;
                //cout << mp[v1[i]] << endl;
            } else
                sorted.pb(v1[i]);
        }
        sort(sorted.begin(), sorted.end());
        FOR(i, 0, m) {
            //cout << mp[v2[i]] << "asa" << endl;
            FOR(j, 0, mp[v2[i]]) {
                cout << v2[i] << " ";
            }
        }
        FOR(i, 0, sorted.size()) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
    return 0;
}