#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int N, revN;
string sN, revSN;
stringstream ss;

void format(string &s)
{
    for (int i = s.length(); i < 4; i++) {
        s = '0' + s;
    }
}

int main()
{
    cin >> sN;
    format(sN);
    if (sN[0] == sN[1] && sN[0] == sN[1] && sN[0] == sN[2] && sN[0] == sN[3]) {
        cout << sN << " - " << sN << " = 0000";
        return 0;
    }
    sort(sN.begin(), sN.end());
    reverse(sN.begin(), sN.end());
    ss << sN;
    ss >> N;
    ss.clear();
    while (true) {
        revSN = sN;
        reverse(revSN.begin(), revSN.end());
        ss << revSN;
        ss >> revN;
        ss.clear();
        printf("%04d - %04d = %04d\n", N, revN, N-revN);
        N = N-revN;
        if (N == 6174) {
            break;
        }
        ss << N;
        ss >> sN;
        format(sN);
        sort(sN.begin(), sN.end());
        reverse(sN.begin(), sN.end());
        ss.clear();
        ss << sN;
        ss >> N;
        ss.clear();
    }
    return 0;
}
