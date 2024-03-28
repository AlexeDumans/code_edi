
#include <iostream>

#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

#define N 4
#define M 2
const int Mod = 1e9 + 7;

int countWays(vector<vector<int>>& ranges) {
    long long sum = 1;
    sort(ranges.begin(), ranges.end());

    for (int i = 0; i < ranges.size();) {
        int j = i + 1;

        int r_max = ranges[i][1];
        cout << ranges[i][0] << " " << ranges[i][1] << endl;
        while (j < ranges.size() && ranges[j][0] <= r_max) {
            r_max = max(r_max, ranges[j][1]);
            j++;
        }
        sum = sum * 2 % Mod;
        i = j;
    }

    return sum;
}


int main() {
    // 快速 OI
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ------输入-------
    // 1. vector<vertor<int>>
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;
            a[i][j] = num;
        }
    }

    // ------------引用 leetcode 函数------------
    countWays(a);
    return 0;
}
