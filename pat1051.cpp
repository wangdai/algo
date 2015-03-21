#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

bool bad = false;
int M, N, K, sp, tmp, seq;
stack<int> s;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &M, &N, &K);
    for (int ri = 0; ri < K; ri++) {
        sp = 0;
        seq= 0;
        bad = false;
        s = *(new stack<int>);
        for (int i = 0; i < N; i++) {
            scanf("%d", &tmp);
            if (!bad) {
                if (!s.empty() && s.top() == tmp) {
                    s.pop();
                    sp--;
                    continue;
                }
                while (true) {
                    sp++;
                    if (sp > M) {
                        bad = true;
                        break;
                    }
                    seq++;
                    if (seq == tmp) {
                        sp--;
                        break;
                    }
                    s.push(seq);
                }
            }
        }
        if (bad) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}
