#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define fs first
#define sc second
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REF(i, a, b) for (ll i = (a); i >= (b); i--)

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
            sudoku[i][j] = 0;
            update(i, j, num, false);
        }
    }
    return false;
}

signed main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    int temp;
    while (cin >> temp) {
        inpu.pb(temp);
    }
    k = 0;
    n = sqrt(inpu.size());
    p = sqrt(n);
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