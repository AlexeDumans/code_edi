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

struct user {
    int size_;
    unordered_map<int, int> feature_;

    user() {}
    user(int size) : size_(size) {}
};

unordered_map<int, user> users;


template <typename T>
set<ll> Myor(T a, T b) {
    return a | b;
}

template <typename T>
set<ll> Myand(T a, T b) {
    return a & b;
}

set<ll> check(int a, int b) {
}

set<ll> rcheck(int a, int b) {
}



stack<string> my_opera; // 操作 & | ( ) : ^
stack<ll> fea_; // 属性 \  值
set<ll> work(string opr) {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    fu(i, 0, n) {
        int id;
        cin >> id;
        int size_;
        cin >> size_;
        user one = user(size_);

        vector<int> fea(size_);
        fu(j, 0, size_) {
            cin >> fea[j];
        }
        fu(j, 0, size_) {
            cin >> one.feature_[fea[j]];
        }
        users[id] = one;
    }

    int m;
    cin >> m;
    while (m--) {
        string opr;
        cin >> opr;
        set<ll> result = work(opr);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}