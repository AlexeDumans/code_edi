#include <iostream>

#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

#define fu(i, l, u) for (ll i = l; i < u; ++i)
#define fd(i, u, l) for (ll i = u; i >= l; --i)

typedef long long ll;

const ll M = 1e9 + 7;

unordered_map<ll, unordered_map<ll, set<ll>>> record;  // 属性 值 用户dn

void Myor(set<ll>& a, set<ll> b) {
    a.insert(b.begin(), b.end());
}

void Myand(set<ll>& a, set<ll> b) {
    set<ll> dead;
    for (auto k : a) {
        if (b.find(k) == b.end()) {
            dead.insert(k);
        }
    }
    for (auto k : dead) {
        a.erase(k);
    }
}

set<ll> check(ll a, ll b) {  // :
    return record[a][b];
}

set<ll> rcheck(ll a, ll b) {  // ^
    set<ll> re;
    for (auto k : record[a]) {
        if (k.first != b) {
            re.insert(k.second.begin(), k.second.end());
        }
    }
    return re;
}

stack<char> my_opera;  // 操作 & | ( ) : ^
stack<ll> fea_;        // 属性 \  值
set<ll> work(string opr) {
    ll num = 0;
    // 压栈
    for (auto k : opr) {
        if (k == '&' | k == '|' | k == '(' | k == ')' | k == ':' | k == '~') {
            my_opera.push(k);
            if (num != 0)
                fea_.push(num);
            num = 0;
        } else if (k >= '0' && k <= '9') {
            ll num_sign = k - '0';
            num = num * 10 + num_sign;
        }
    }
    if (num != 0)
        fea_.push(num);

    ll level = 0;
    vector<queue<set<ll>>> temp_re(700);  // 不同层的暂存结果;
    set<ll> last_result;
    while (!my_opera.empty()) {
        char a = my_opera.top();
        my_opera.pop();
        if (a == ')') {  // 加层
            level++;
            continue;
        }
        if (a == '(') {
            level--;
            continue;
        }
        if (a == ':') {
            int value = fea_.top();
            fea_.pop();
            int key = fea_.top();
            fea_.pop();
            temp_re[level].push(check(key, value));
            continue;
        }
        if (a == '~') {
            int value = fea_.top();
            fea_.pop();
            int key = fea_.top();
            fea_.pop();
            temp_re[level].push(rcheck(key, value));
            continue;
        }
        if (a == '|') {
            set<ll> first_re = temp_re[level + 1].front();
            temp_re[level + 1].pop();
            set<ll> second_re = temp_re[level + 1].front();
            temp_re[level + 1].pop();
            Myor(first_re, second_re);
            temp_re[level].push(first_re);
            continue;
        }
        if (a == '&') {
            set<ll> first_re = temp_re[level + 1].front();
            temp_re[level + 1].pop();
            set<ll> second_re = temp_re[level + 1].front();
            temp_re[level + 1].pop();
            Myand(first_re, second_re);
            temp_re[level].push(first_re);
            continue;
        }
    }
    last_result = temp_re[0].front();
    return last_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    fu(i, 0, n) {
        ll size_, id;
        cin >> id >> size_;
        // vector<ll> fea(7000);  // 属性
        fu(j, 0, size_) {
            int key;
            cin >> key;
            int value;
            cin >> value;
            record[key][value].insert(id);
        }
    }

    ll m;
    cin >> m;
    for (int k = 0; k < m; ++k) {
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