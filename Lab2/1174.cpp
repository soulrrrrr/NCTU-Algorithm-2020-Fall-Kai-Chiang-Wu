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
 * 依題意建function
 * key:二分
 * time:O(nlogn) 40ms
****************************************************************/

int n;

bool comp(string a, string b) {
    if (a == b)
        return true;
    else if (a.size() & 1 || b.size() & 1) // 判斷是否為奇數
        return false;
    else {
        string a1 = a.substr(0, a.size() / 2);
        string a2 = a.substr(a.size() / 2);
        string b1 = b.substr(0, b.size() / 2);
        string b2 = b.substr(b.size() / 2);
        return ((comp(a1, b1) && comp(a2, b2)) || (comp(a1, b2) && comp(a2, b1)));
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a;
        cin >> b;
        if (comp(a, b))
            cout << "Yes"
                 << "\n";
        else
            cout << "No"
                 << "\n";
    }
    return 0;
}