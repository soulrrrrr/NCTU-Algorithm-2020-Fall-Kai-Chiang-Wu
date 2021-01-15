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
 * 開bool陣列紀錄各行/列/方格的數字有沒有被選過
 * eg.row[3][5] = 1 表示第4列已經有5了
 * key:backtracking
 * time: 4,024ms
****************************************************************/

int k = 0, n = 0, p;
int sudoku[25][25];
bool row[25][26];
bool col[25][26];
bool block[5][5][26];
vector<int> inpu;

void printSudoku() {
    //cout << "a";
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

void update(int i, int j, int num, bool b) {
    row[i][num] = b;
    col[j][num] = b;
    block[i / p][j / p][num] = b;
}

bool usedInRow(int i, int num) {
    return row[i][num];
}

bool usedInCol(int j, int num) {
    return col[j][num];
}

bool usedInBlock(int i, int j, int num) {
    return block[i / p][j / p][num];
}

bool legal(int i, int j, int num) {
    //cout << i << " " << j << " " << num << endl;
    return !(usedInRow(i, num) || usedInCol(j, num) || usedInBlock(i, j, num) || sudoku[i][j] != 0);
}

bool find0(int &i, int &j) {
    for (i; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (sudoku[i][j] == 0)
                return true;
        }
    }
    return false;
}

bool solve(int i, int j) {
    if (!find0(i, j))
        return true;

    for (int num = 1; num <= n; num++) {
        if (legal(i, j, num)) {
            sudoku[i][j] = num;
            update(i, j, num, true);
            if (solve(i, j + 1))
                return true;
            sudoku[i][j] = 0;         // 退回時要改回0
            update(i, j, num, false); // 退回時要改回沒有用過該數字
        }
    }
    return false;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int temp;
    while (cin >> temp) {
        inpu.pb(temp);
    }
    k = 0;
    n = sqrt(inpu.size());
    p = sqrt(n); // 數獨的邊長
    //cout << p << endl;
    //cout << n << endl;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (k < n * n) {
                sudoku[i][j] = inpu[k];
                update(i, j, sudoku[i][j], true);
                k++;
            }
        }
    }
    if (!solve(0, 0))
        cout << "NO" << endl;
    else
        printSudoku();

    return 0;
}