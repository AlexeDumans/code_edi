
#include <iostream>

#include <fstream>
#include <sstream>
#include <string.h>

#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

#define N 200005
const int Mod = 1e9 + 7;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> wordset = set<string>(wordList.begin(), wordList.end());
    int word_len = beginWord.length();

    unordered_map<string, int> visited;

    queue<string> bfs_que;
    bfs_que.push(beginWord);
    visited[beginWord] = 1;

    while (!bfs_que.empty()) {
        string current_word = bfs_que.front();
        bfs_que.pop();

        for (int i = 0; i < word_len; ++i) {
            string change_word = current_word;
            for (char j = 'a'; j <= 'z'; ++j) {
                change_word[i] = j;
                if (change_word == current_word)
                    continue;
                if (wordset.find(change_word) != wordset.end() && visited.find(change_word) == visited.end()) {
                    bfs_que.push(change_word);
                    visited[change_word] = visited[current_word] + 1;
                }

                if (!strcmp(change_word.c_str(), endWord.c_str())) {
                    return visited[change_word];
                }
            }
        }
    }
    return 0;
}

int main() {
    // 快速 OI
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ------输入-------
    // 1. string
    string a = "";

    string b = "";
    cin >> a >> b;
    vector<string> c(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }

    // ------------引用 leetcode 函数------------
    cout << ladderLength(a, b, c);

    return 0;
}
