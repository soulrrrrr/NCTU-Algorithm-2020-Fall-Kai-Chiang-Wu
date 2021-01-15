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
 * 按字典序大小排序
 * 排序方法為兩兩數字放前放後，看哪個比較大就照哪個
 * key:greedy
 * time:O(nlogn)
****************************************************************/

bool cp(string a, string b) {
    return (a + b > b + a);
}

int main() {
    int ncases;
    cin >> ncases;
    FOR(i, 0, ncases) {
        vector<string> v;
        int nums;
        cin >> nums;
        FOR(j, 0, nums) {
            string s;
            cin >> s;
            v.pb(s);
        }
        sort(v.begin(), v.end(), cp);
        for (auto i : v)
            cout << i;
        cout << endl;
    }

    return 0;
}