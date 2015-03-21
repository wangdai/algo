#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N, L, MI, ULI, K, sender;
vector<int> g[1100];
int flag[1100];
int count;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &L);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &MI);
        for (int j = 1; j <= MI; j++) {
            scanf("%d", &ULI);
            g[ULI].push_back(i); // 这里倒过来存
        }
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &sender);
        count = 0;
        for (int j = 1; j <= N; j++) {
            flag[j] = 0;
        }
        flag[sender] = 1;

        queue<pair<int, int> > q = *(new queue<pair<int, int> >); // clear queue

        /*** BFS ***/
        q.push(pair<int, int>(sender, 1));
        while (!q.empty()) {
            int a = q.front().first;
            int depth = q.front().second;
            if (depth > L) {
                break;
            }
            q.pop();
            for (int k=0; k<g[a].size(); k++) {
                int b = g[a][k];
                if (flag[b] == 0) {
                    flag[b] = 1;
                    count++;
                    q.push(pair<int, int>(b, depth+1));
                }
            }
        }
        /*** end-of BFS ***/
        printf("%d\n", count);
    } // end-of for loop
    return 0;
}

/**
 * 必须要倒过来存，而且直接存数字而不是存整张图，否则最后一个点会超时。
 * 最好用BFS，DFS没法剪枝，最后一个点肯定超时
 */
