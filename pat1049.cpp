#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int pow(int di, int zhi) {
    if (zhi < 0) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < zhi; i++) {
        res *= di;
    }
    return res;
}

int main()
{
    int count = 0;
    int NN;
    string N;
    stringstream ss;
    cin >> N;
    ss << N;
    ss >> NN;
    int len = N.length();
    int num = 0;
    for (int i = 0; i < len; i++) {
        int digit = N[i]-'0';
        num = num * 10 +digit;
        if (digit > 1) {
            count += pow(10, len-i-1);
        }
        else if (digit == 1) {
            count += (NN-num*pow(10, len-i-1)+1);
        }
        count += num*pow(10, len-i-2);
    }
    cout << count;
    return 0;
}
