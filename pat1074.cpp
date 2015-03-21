#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int N, K;

struct Node {
    int addr;
    int nadd;
    int value;
    Node *next;
    Node *prev;
};

int main()
{
    //freopen("aa.txt", "r", stdin);

    int start;
    //cin >> start >> N >> K;
    scanf("%d%d%d", &start, &N, &K);

    Node *head;
    Node *origin = new Node[N];
    for (int i = 0; i < N; i++) {
        origin[i].next = NULL;
        origin[i].prev = NULL;
    }

    int stop;
    for (int i = 0; i < N; i++) {
        //cin >> origin[i].addr >> origin[i].value >> origin[i].nadd;
        scanf("%d%d%d", &origin[i].addr, &origin[i].value, &origin[i].nadd);
        if (origin[i].addr == start) {
            head = &origin[i];
            stop = origin[i].nadd;
            if (stop == -1) {
                printf("%.05d %d -1", origin[i].addr, origin[i].value);
                return 0;
            }
        }
    }

    Node *p = head;
    bool isTail = false;
    int length = 1;
    while (true) {
        for (int i = 0; i < N; i++) {
            if (origin[i].addr == stop) {
                p->next = &origin[i];
                p->next->prev = p;
                p = p->next;
                stop = origin[i].nadd;
                length++;
                if (stop == -1) {
                    isTail = true;
                    break;
                }
            }
        }
        if (isTail) {
            break;
        }
    }

    p = head;
    bool isFirst = true;
    for (int i = 0; i < length; i++, p = p->next) {
        if (i % K == K - 1) {
            Node *q = p;
            for (int j = 0; j < K; j++, q = q->prev) {
                if (isFirst) {
                    isFirst = false;
                }
                else {
                    //cout << " " << q->addr << endl;
                    printf(" %.05d\n", q->addr);
                }
                //cout << q->addr << " " << q->value;
                printf("%.05d %d", q->addr, q->value);
            }
        }
        if (i >= length - length % K) {
            //cout << " " << p->addr << endl;
            //cout << p->addr << " " << p->value;
            printf(" %.05d\n", p->addr);
            printf("%.05d %d", p->addr, p->value);
        }
    }
    printf(" -1\n");

    return 0;
}
