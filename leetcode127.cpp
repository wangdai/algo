/**
 * leetcode 127 - Word Ladder
 * https://leetcode.com/problems/word-ladder/
 *
 * please compile it with -std=c++11
 * easy BFS, but this solution is slow, why??
 * do NOT iterating dict! slow!
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

/* this method is 5 time faster than the above one */
/* use dict.find() instead of iterating over it */
int ladder_length_fast(string start, string end, unordered_set<string> &dict)
{
    if (start == end) {
        return 1;
    }
    int len = start.length();
    queue<pair<string,int>> que;
    que.push(pair<string,int>(start, 1));
    while (!que.empty()) {
        auto tt = que.front(); que.pop();
        string s = tt.first;
        int dist = tt.second;
        if (is_neighbour(s, end)) {
            return dist+1;
        }
        for (int i = 0; i < len; i++) {
            char tmp = s[i];
            for (int c = 0; c < 26; c++) {
                s[i] = 'a' + c;
                auto iu = dict.find(s);
                if (iu != dict.end()) {
                    que.push(pair<string,int>(s, dist+1));
                    dict.erase(iu);
                }
            }
            s[i] = tmp;
        }
    }
    return 0;
}

int main()
{
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    unordered_set<string> dict2({"hot","dot","dog","lot","log"});
    assert(5 == ladder_length("hit", "cog", dict));
    assert(5 == ladder_length_fast("hit", "cog", dict2));
    return 0;
}
