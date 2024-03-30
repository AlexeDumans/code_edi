
#include <iostream>

#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

#define M 2
const int Mod = 1e9 + 7;

#define fu(i, l, u) for (int i = l; i < u; ++i)
#define fd(i, u, l) for (int i = u; i > l; --i)
const int N = 20000;

vector<int> father(N);

void init() {
    fu(i, 0, N) {
        father[i] = i;
    }
}

int find(int i) {
    return father[i] == i ? i : father[i] = find(father[i]);
}

bool isSame(int i, int j) {
    i =find(i);
    j = find(j);
    return i == j;
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j)
        return;
    father[j] = i;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    init();

    fu(i, 0, edges.size()) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (isSame(u, v)) {
            return edges[i];
        }
        join(u, v);
    }
    return vector<int>{};
}
int main() {
    // 快速 OI
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ------输入-------
    // 1. vector<vector<int>>
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
        }
    }

    // 一个简单的遍历二维数组的
    // for (int i = 0; i < array_.size(); ++i) {
    //     for (int j = 0; j < array_[0].size(); ++j) {
    //     }
    // }

    // ------------引用 leetcode 函数------------
    cout << findRedundantConnection(a)[0] << " " << findRedundantConnection(a)[1] << endl;
    return 0;
}
