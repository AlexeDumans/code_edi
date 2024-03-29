#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void NO() { cout << "NO\n"; }
void YES() { cout << "YES\n"; }

#define fu(i, l, u) for (int i = l; i < u; ++i)
#define fd(i, u, l) for (int i = u - 1; i >= l; --i)

// 八方向
vector<vector<int>> dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {0, 1}, {-1, -1}, {0, -1}, {1, -1}};
unordered_map<int, set<array<int, 2>>> row, col, lline, rline;
struct Staff {
    int x, y;
    int id;
    Staff(int a, int b, int c) {
        x = a;
        y = b;
        id = c;
    }
} staffs_[100010];

// map_insert
void map_insert(int id) {
    int x = staffs_[id].x;
    int y = staffs_[id].y;
    row[x].insert({y, id});
    col[y].insert({x, id});
    lline[x + y].insert({x, id});
    row[x - y].insert({x, id});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    fu(i, 0, p) {
        cin >> staffs_[i].x >> staffs_[i].y;
        map_insert(i);
    }
    // q yin yang dragon
    fu(i, 0, q) {
        int u, v, t;
        cin >> u >> v >> t;

        int min_distence = min({n - u, u - 1, m - v, v - 1});

        // 获取位置
        vector<Staff> scope_staff;
        auto search = [&](const set<array<int, 2>>& people, int d, int dirr, int dirl) {
            auto pos = people.lower_bound(array<int, 2>{d, p});  // 二分查找

            if (pos != people.end()) {
                candidate.push_back({(*pos)[0] - d, (*pos)[1], dirr});
            }
            if (pos != people.begin()) {
                pos = prev(pos);
                if ((*pos)[0] == d && pos != people.begin())
                    pos = prev(pos);
                // pos = next(pos);
                if ((*pos)[0] != d) {
                    candidate.push_back({d - (*pos)[0], (*pos)[1], dirl});
                }
            }
        };


        // 比较是否在范围内

        // 移动
    }

    // ans
    ll ans = 0;
    fu(i, 0, p) {
        ans ^= (i + 1) * staffs_[i].x + staffs_[i].y;
    }
    cout << ans << endl;
    return 0;
}