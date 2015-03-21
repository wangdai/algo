#include <cstdio>
#include <cstring>

using namespace std;

char s1[30];
char s2[30];
int c1[10];
int c2[10];

int main()
{
    scanf("%s", s1);
    int len = strlen(s1);
    int carry = 0;
    for (int i = len-1; i >= 0; i--) {
        int ddc = (s1[i]-'0')*2 + carry;
        if (ddc >= 10) {
            s2[i] = ddc - 10 + '0';
            carry = 1;
            if (i == 0) {
                printf("No\n");
                printf("1%s", s2);
                return 0;
            }
        }
        else {
            s2[i] = ddc + '0';
            carry = 0;
        }
    }
    for (int i = 0; i < len; i++) {
        c1[s1[i]-'0']++;
        c2[s2[i]-'0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (c1[i] != c2[i]) {
            printf("No\n");
            printf("%s", s2);
            return 0;
        }
    }
    printf("Yes\n");
    printf("%s", s2);
    return 0;
}
