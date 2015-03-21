#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    string text = "";
    string temp = "";
    map<string, int> frequency;
    map<string, int>::iterator freIter;

    char c = 0;
    while ((c = getchar()) != '\n') {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            temp = temp + c;
        }
        if (temp != "" && !(c >= 'a' && c <= 'z' || c >= '0' && c <= '9')) {
            frequency[temp]++;
            temp = "";
        }
    }
    if (temp != "") {
        frequency[temp]++;
        temp = "";
    }

    int max = 0;
    string maxString = "";
    for (freIter = frequency.begin(); freIter != frequency.end(); freIter++) {
        if (freIter->second > max) {
            max = freIter->second;
            maxString = freIter->first;
        }
    }

    cout << maxString << " " << max;

    return 0;
}
