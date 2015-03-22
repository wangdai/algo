/**
 * leetcode 44 - Wildcard Matching
 * https://leetcode.com/problems/wildcard-matching/
 *
 * my solution is DFS backtracking and clipping
 *
 * @author wangdai
 * @date 2015-03-21
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

// wrapper
bool isMatch(const char* s, const char* p)
{
    return is_match(s, p) > 0;
}

// returning -1 means exit the recurse and returns FALSE directly
int is_match(const char* s, const char* p)
{
    while (*s) {
        if (*s == *p || *p == '?') {
            s++;
            p++;
        } else if (*p == '*') {
            while (*++p == '*');
            if (*p == 0) {
                return 1;
            }
            while (*s) {
                int r = is_match(s, p);
                if (r == 1) {
                    return 1;
                } else if (r == -1) {
                    return -1;
                }
                s++;
            }
            return -1;
        } else {
            return 0;
        }
    }
    while (*p) {
        if (*p != '*') {
            return -1;
        }
        p++;
    }
    return 1;
}

int main()
{
    assert(false == isMatch("aa","a"));
    assert(false == isMatch("aa","aa"));
    assert(false == isMatch("aaa","aa"));
    assert(false == isMatch("aa", "*"));
    assert(false == isMatch("aa", "a*"));
    assert(false == isMatch("ab", "?*"));
    assert(false == isMatch("aab", "c*a*b"));
    
    assert(-1 == is_match(
        "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
        "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
    ));
    return 0;
}
