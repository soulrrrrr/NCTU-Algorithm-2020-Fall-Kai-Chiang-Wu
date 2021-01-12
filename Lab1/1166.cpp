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
 * 紀錄最大值，開該大小的array
 * array的index代表數字，裡面的value代表數字出現幾次
 * 紀錄總共出現多少種數字，及出現最多次的數字的次數
 * 會有兩種情況
 * 一種是出現最多次的數字的其中一次算在出現幾種數字，取min
 * 另一種是出現最多次的數字不在出現幾種數字裡，取min
 * 兩者取max
 * key: naive solution
****************************************************************/

void solve() {
    int n;
    cin >> n;
    int maxx = 0;
    vector<int> b;
    FOR(i, 0, n) {
        int temp;
        cin >> temp;
        b.pb(temp);
        maxx = max(maxx, temp);
    }
    vector<int> ctSorted(maxx + 1, 0);
    vector<int> output(n, 0);
    int nums = 0;
    FOR(i, 0, n) {
        if (ctSorted[b[i]] == 0)
            nums++;
        ctSorted[b[i]]++;
    }
    sort(ctSorted.begin(), ctSorted.end(), greater<int>());
    cout << max(min(nums, ctSorted[0] - 1), min(nums - 1, ctSorted[0])) << endl;
}

int main() {
    int ncases;
    cin >> ncases;
    FOR(i, 0, ncases) {
        solve();
    }
    return 0;
}