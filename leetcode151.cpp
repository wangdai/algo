/**
 * leetcode 151 - Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * here is a one pass and O(1) space solution
 *
 * @author wangdai
 * @date 2015-03-21
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void reverse_words(string& s)
{
    string r = "";
    int tail;
    for (int i =s.length()-1; i >= 0; i--) {
        if ((i < s.length() && s[i+1] == ' ' && s[i] != ' ') ||
            (i == s.length() && s[i] != ' ')) {
            tail = i;
        }
        if ((i > 0 && s[i] != ' ' && s[i-1] == ' ') ||
            (i == 0 && s[i] != ' ')) {
            r.append(s.substr(i, tail-i+1) + ' ');
        }
    }
    if (r.length() > 0 && r[r.length()-1] == ' ') {
        r.erase(r.end()-1);
    }
    s = r;
}

int main()
{
    string s = "the sky is blue";
    reverse_words(s);
    cout << s; // expected output "blue is sky the"
    return 0;
}
