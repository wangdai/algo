#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N1, N2, i, c1, c2;
long long a1[1000000];
long long a2[1000000];

int main()
{
    scanf("%d", &N1);
    for (i = 0; i < N1; i++) {
        scanf("%lld", &a1[i]);
    }
    scanf("%d", &N2);
    for (i = 0; i < N2; i++) {
        scanf("%lld", &a2[i]);
    }
    i = 0;
    bool endFlag1 = false;
    bool endFlag2 = false;
    while (true) {
        if (endFlag2 || (!endFlag1 && a1[c1] <= a2[c2])) {
            if (i == (N1+N2-1)/2) {
                printf("%lld", a1[c1]);
                break;
            }
            if (c1 >= N1-1) {
                endFlag1 = true;
            }
            else {
                c1++;
            }
        }
        else {
            if (i == (N1+N2-1)/2) {
                printf("%lld", a2[c2]);
                break;
            }
            if (c2 >= N2-1) {
                endFlag2 = true;
            }
            else {
                c2++;
            }
        }
        i++;
    }
    return 0;
}
