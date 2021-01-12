#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)

bool cp(string a, string b) {
    return (a+b > b+a);
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
        for (auto i : v) cout << i;
        cout << endl;
    }
    
    return 0;
}