#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)

/****************************************************************
 * 在讀入資料時找到pivot記錄下來
 * pivot左和右都是sorted array,可以用binary search找題目要找的數字
 * key: binary search
 * time: O(mlogm)
****************************************************************/

int pivot;
class Solution {
public:
    int search(vector<int> &nums, int target) {
        auto it_1 = lower_bound(nums.begin() + pivot, nums.end(), target);
        if (it_1 != nums.end() && *it_1 == target)
            return it_1 - nums.begin();

        auto it_2 = lower_bound(nums.begin(), nums.begin() + pivot, target);
        if (it_2 != (nums.begin() + pivot) && *it_2 == target)
            return it_2 - nums.begin();
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int tmp;
    vector<int> v;
    Solution sol;
    cin >> M >> N;

    FOR(i, 0, M) {
        cin >> tmp;
        v.push_back(tmp);
        if (v[i] < v[i - 1])
            pivot = i;
    }

    while (N--) {
        cin >> tmp;
        cout << sol.search(v, tmp) << endl;
    }

    return 0;
}