
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
int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    unordered_map<int, int> count_visit;
    int n = nextVisit.size();
    count_visit[0] = 1;
    int next_room = nextVisit[0];
    long long day_ = 0;
    // 暴力
    while (count_visit.size() != n) {
        count_visit[next_room]++;
        if (count_visit[next_room] % 2 == 1) {
            next_room = nextVisit[next_room];
        } else {
            next_room = (next_room + 1) % n;
        }
        day_++;
    }
    return day_ % Mod;
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

    cout << firstDayBeenInAllRooms(a);
    return 0;
}
