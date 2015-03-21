#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int coin[100005];

int main()
{
    //freopen("input2.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    sort(coin, coin+N);

    for (int i = 0; i < N; i++) {
        int K = M -coin[i];
        if (binary_search(coin+i+1, coin+N, K)) {
            printf("%d %d", coin[i], K);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
