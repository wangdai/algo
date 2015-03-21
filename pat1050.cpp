#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    char c;
    set<char> s;
    while ((c = getchar()) != '\n') {
        s.insert(c);
    }

    for (int i = 0; i < line.length(); i++) {
        if (s.find(line[i]) == s.end()) {
            cout << line[i];
        }
    }
    return 0;
}
