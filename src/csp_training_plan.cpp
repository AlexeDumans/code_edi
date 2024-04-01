#include <iostream>

#include <string.h>
#include <sstream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

#define fu(i, l, u) for (int i = l; i < u; ++i)
#define fd(i, u, l) for (int i = u; i >= l; --i)

typedef long long ll;

const int M = 1e9 + 7;

vector<int> depend_(110, 0);
vector<set<int>> prev_(110);
vector<int> day_(110, 0);
vector<int> visited(110, 0);
vector<int> earlist(110, 0);
vector<int> last(110, 0);

void dfs(vector<int> depend_, vector<int> day_, int i) {
    if (visited[i] == 1) {
        return;
    }

    visited[i] = 1;

    if (depend_[i] == 0) {
        earlist[i] = 1;
        return;
    }

    dfs(depend_, day_, depend_[i]);

    earlist[i] = earlist[depend_[i]] + day_[depend_[i]];
}

void dfs_last(int i, int n) {
    if (visited[i] == 1) {
        return;
    }

    visited[i] = 1;

    if (prev_[i].empty()) {
        last[i] = n - day_[i] + 1;
        return;
    }

    for(auto k :prev_[i]){
        dfs_last(k, n);
    }

    int max_ = INT_MAX;
    for(auto k :prev_[i]){
        if(max_ > last[k]){
            max_ = last[k];
        }
    }

    last[i] = max_ - day_[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // id from 1

    fu(i, 1, m + 1) {
        cin >> depend_[i];
    }
    fu(i, 1, m + 1) {
        cin >> day_[i];
    }

    fu(i, 1, m + 1) {
        prev_[depend_[i]].insert(i);
        dfs(depend_, day_, i);
    }

    fu(i, 1, m + 1) {
        cout << earlist[i] << " ";
    }

    cout << endl;
    int flag = 0;
    fu(i, 1, m + 1) {
        if (day_[i] + earlist[i] - 1 > n) {
            flag = 1;
        }
    }
    if (flag) {
        return 0;
    }

    visited.clear();
    visited = vector<int>(110, 0);

    fu(i, 1, m + 1) {
        dfs_last(i, n);
    }

    fu(i, 1, m + 1) {
        cout << last[i] << " ";
    }

    return 0;
}