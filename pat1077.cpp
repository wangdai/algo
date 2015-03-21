#include <iostream>
#include <cstdio>

using namespace std;

int N;
string line[102];

int main()
{
    //freopen("aa.txt", "r", stdin);

    int minLen = 1000000;
    cin >> N;
    cin.get();
    for (int i =0; i < N; i++) {
        getline(cin, line[i]);
        if (line[i].length() < minLen) {
            minLen = line[i].length();
        }
    }

    string suffix = "";
    bool b = false;
    for (int j = 0; j < minLen; j++) {
        for (int i = 0; i < N; i++) {
            int L = line[i].length();
            char c = line[i][L-1-j];
            if (i == 0) {
                suffix = c + suffix;
            }
            else if (c != suffix[0]) {
                suffix = suffix.substr(1);
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }

    if (suffix == "") {
        cout << "nai";
    }
    else {
        cout << suffix;
    }
    return 0;
}
