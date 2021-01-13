#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
#define int ll
int n, k;
vector<vector<int>> v;
vector<vector<int>> ans;

/****************************************************************
 * 先按距離sort
 * 再把前k個點用x,y順序sort
 * key:brute force
 * time:O(nlogn)
****************************************************************/

bool cmp(vector<int> const &v1, vector<int> const &v2) {
    return (v1[2] < v2[2] /*|| ((v1[2] == v2[2]) && (v1[0] > v2[0])) || ((v1[2] == v2[2]) && (v1[0] == v2[0]) && (v1[1] >= v2[1]))*/);
}

bool cmp2(vector<int> const &v1, vector<int> const &v2) {
    return ((v1[0] > v2[0]) || (v1[0] == v2[0]) && (v1[1] > v2[1]));
}

signed main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n >> k;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b, a * a + b * b});
    }
    sort(v.begin(), v.end(), cmp);
    sort(v.begin(), v.begin() + k, cmp2);
    int i = 0;
    while (i < k) {
        cout << v[i][0] << " " << v[i][1] << "\n";
        i++;
    }
    return 0;
}