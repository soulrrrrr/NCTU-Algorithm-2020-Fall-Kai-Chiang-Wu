#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)
//#define int ll

int n;

bool comp(string a, string b) {
    if (a == b) return true;
    else if (a.size() & 1 || b.size() & 1) return false;
    else {
        string a1 = a.substr(0, a.size()/2);
        string a2 = a.substr(a.size()/2);
        string b1 = b.substr(0, b.size()/2);
        string b2 = b.substr(b.size()/2);
        return ((comp(a1, b1) && comp(a2, b2)) || (comp(a1, b2) && comp(a2, b1)));
    }
}

signed main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n;
    while(n--) {
        string a, b;
        cin >> a;
        cin >> b;
        if (comp(a, b)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}