
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
#include <climits>

using namespace std;

#define N 5

const int Mod = 1e9 + 7;

void dfs(vector<vector<int>>& rooms, int i, vector<bool>& visited) {
    if (visited[i])
        return;
    visited[i] = true;
    for (auto k : rooms[i]) {
        dfs(rooms, k, visited);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);
    dfs(rooms, 0, visited);
    // 检查是否都访问到了
    for (int i : visited) {
        if (i == false)
            return false;
    }
    return true;
}
int main() {
    // 快速 OI
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ------输入-------
    // 1.  vector<int>
    vector<int> a(N);
    for (int j = 0; j < N; ++j) {
        int num;
        cin >> num;
        a[j] = num;
    }

    cout << minimumSum(a);
    return 0;
}
