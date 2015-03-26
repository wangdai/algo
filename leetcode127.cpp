/**
 * leetcode 127 - Word Ladder
 * https://leetcode.com/problems/word-ladder/
 *
 * please compile it with -std=c++11
 * easy BFS, but this solution is slow, why??
 *
 * @author wangdai
 * @date 2015-03-21
 */

#include <string>
#include <cstdlib>
#include <cassert>
#include <unordered_set>
#include <queue>

using namespace std;

bool is_neighbour(const string &a, const string &b)
{
    if (a.length() != b.length() || a == b) {
        return false;
    }
    int count = 0;
    for (unsigned i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            count++;
            if (count > 1) {
                return false;
            }
        }
    }
    return true;
}

int ladder_length(string start, string end, unordered_set<string> &dict)
{
    if (start == end) {
        return 1;
    }
    queue<pair<string, int>> que;
    que.push(pair<string, int>(start, 1));
    while (!que.empty()) {
        auto tmp = que.front();que.pop();
        string s = tmp.first;
        int dist = tmp.second;
        if (is_neighbour(s, end)) {
            return dist+1;
        }
        for (auto it = dict.begin(); it != dict.end();) {
            if (is_neighbour(s, *it)) {
                que.push(pair<string, int>(*it, dist+1));
                it = dict.erase(it);
            } else {
                it++;
            }
        }
    }
    return 0;
}

int main()
{
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    assert(5 == ladder_length("hit", "cog", dict));
    return 0;
}
