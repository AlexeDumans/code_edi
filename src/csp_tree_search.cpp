#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define N 1e7

#define fu(i, l, u) for (int i = l; i < u; ++i)
#define fd(i, u, l) for (int i = u - 1; i >= l; --i)

vector<int> W_n;
vector<int> U_n;          // 上级
vector<int> Sum_child_n;  // 后代和

ll sum_w = 0;

bool vs(int n, int ans) {
    unordered_map<int, bool> dele_n;
    dele_n.clear();

    dele_n[n] = true;

    fu(i, 1, Sum_child_n.size()) {
        fu(i, 1, Sum_child_n.size()) {
            if (U_n[i] == n) {
                dele_n[i] = true;
            }
            if (dele_n.find(U_n[i]) != dele_n.end()) {
                dele_n[i] = true;
            }
        }
    }

    if (dele_n.find(ans) == dele_n.end()) {
        return false;
    }
    return true;
}

//
int compu_min(int ans, ll& sum, vector<int>& sum_child_n, int& nums, unordered_map<int, bool>& dele_n) {
    ll min_abs = LLONG_MAX;
    int n = 0;

    fu(i, 1, sum_child_n.size()) {
        if (sum_child_n[i] > 0) {
            ll a = abs(sum - 2 * sum_child_n[i]);
            if (a < min_abs) {
                min_abs = a;
                n = i;
            }
        }
    }

    if (vs(n, ans)) {
        // 找子树保留
        dele_n[n] = true;
        fu(i, n, sum_child_n.size()) {
            if (dele_n.find(U_n[i]) != dele_n.end()) {
                dele_n[i] = true;
            }
        }

        // 不在其中的去除
        fu(i, 1, sum_child_n.size()) {
            if (dele_n.find(i) == dele_n.end() && sum_child_n[i] > 0) {
                sum_child_n[i] = 0;
                nums--;
            }
        }

        sum = sum_child_n[n];
        return n;
    }

    // 去除 父亲节点 减权重和
    int UP_n = n;
    while (UP_n != 1) {
        UP_n = U_n[UP_n];
        sum_child_n[UP_n] -= sum_child_n[n];
    }

    sum -= sum_child_n[n];

    // 找子树
    dele_n[n] = true;
    fu(i, n, sum_child_n.size()) {
        if (dele_n.find(U_n[i]) != dele_n.end()) {
            dele_n[i] = true;
        }
    }
    fu(i, n, sum_child_n.size()) {
        // 在的去除
        if (dele_n.find(i) != dele_n.end() && sum_child_n[i] > 0) {
            sum_child_n[i] = 0;
            nums--;
        }
    }

    return n;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 权重

    W_n.push_back(-1);

    // 数字从1开始
    fu(i, 1, n + 1) {
        ll w;
        cin >> w;
        W_n.push_back(w);
        sum_w += w;
    }

    // 上级编号
    U_n.push_back(-1);
    U_n.push_back(0);
    fu(i, 2, n + 1) {
        int up;
        cin >> up;
        U_n.push_back(up);
    }

    // 后代和
    unordered_map<int, ll> sum_ch;
    Sum_child_n = vector<int>(n + 1);
    fd(i, n + 1, 1) {
        Sum_child_n[i] = W_n[i] + sum_ch[i];
        sum_ch[U_n[i]] += Sum_child_n[i];
    }
    Sum_child_n[1] = sum_w;

    // 回答
    while (m--) {
        int ans;  // 回答
        cin >> ans;

        ll W_sum = sum_w;  // 初始化权重和
        vector<int> w_n = Sum_child_n;

        int result = 0;
        int nums = n;

        do {
            unordered_map<int, bool> dele_num;
            dele_num.clear();
            result = compu_min(ans, W_sum, w_n, nums, dele_num);
            cout << result << " ";  // 返回 拆分值
        } while (nums != 1);
        cout << endl;
    }

    return 0;
}