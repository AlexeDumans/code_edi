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

vector<int> C;

vector<int> U;

vector<int> V;

vector<int> D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, l, k;

    C = vector<int>(n);
    fu(i, 0, n) {
        cin >> C[i];
    }

    U = vector<int>(n);
    V = vector<int>(n);
    D = vector<int>(n);
    fu(i, 0, m) {
        cin >> U[i];
    }
    fu(i, 0, m) {
        cin >> V[i];
    }
    fu(i, 0, m) {
        cin >> D[i];
    }


    

    return 0;
}