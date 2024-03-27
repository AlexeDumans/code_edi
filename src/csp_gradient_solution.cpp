#include <iostream>
// #include <stdlib>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

#define ll long long

#define M 1e9 + 7

#define fu(i, l, u) for (int i = l; i < u; ++i)
#define fd(i, u, l) for (int i = u - 1; i >= l; --i)

// 0 - 常数 1 -n 变量
enum type_num { coe,
                vec };
vector<int> formal;
struct f_ {
    ll coe;
    vector<int> formal{vector<int>(101)};
    f_(ll i, vector<int> a) : coe(i), formal(a) {}
};
stack<f_> st_;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> x_n;
    getchar();

    string str;
    getline(cin, str);
    string temp;
    stringstream sin_(str);
    while (sin_ >> temp) {
        if (temp == "+" || temp == "*" || temp == "-") {
            f_ a = st_.top();
            st_.pop();

            f_ b = st_.top();
            st_.pop();
        } else {
            if (temp[0] != 'x') {
                ll coe = stoi(temp);
                st_.push(f_(coe, NULL));
            } else {
                ll coe = stoi(temp);
                st_.push(f_(coe, NULL));
            }
        }
    }

    stack<string> compu;

    fd(i, str.size() - 1, 0) {
        compu.push(str[]);
    }

    fu(i, 0, m) {
        int x;
        cin >> x;
        vector<int> m;
    
        int result = 0;

        cout << result;
    }

    return 0;
}