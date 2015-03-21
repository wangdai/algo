#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int N, m;
int a[3000];
int res[3000];
struct Tree {
    int left;
    int mid;
    int right;
};
queue<Tree> q;

int calMid(int num)
{
    if (num <= 0) {
        return 0;
    }
    int level = log(num/2 + 1) / log(2);
    int leaf = num - 2*(pow(2,level)-1);
    if (leaf > pow(2, level)) {
        return int(pow(2, level+1)-1);
    }
    else {
        return int(pow(2,level)-1 + leaf);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    Tree root;
    root.left = 0;
    root.right = N-1;
    root.mid = calMid(N-1);
    q.push(root);
    while (!q.empty()) {
        Tree node = q.front();
        q.pop();
        res[m++] = a[node.mid];
        Tree lSubTree, rSubTree;
        if (node.mid > node.left) {
            lSubTree.left = node.left;
            lSubTree.right = node.mid - 1;
            lSubTree.mid = lSubTree.left + calMid(lSubTree.right-lSubTree.left);
            q.push(lSubTree);
        }
        if (node.mid < node.right) {
            rSubTree.left = node.mid + 1;
            rSubTree.right = node.right;
            rSubTree.mid = rSubTree.left + calMid(rSubTree.right-rSubTree.left);
            q.push(rSubTree);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d", res[i]);
        if (i < N-1) {
            printf(" ");
        }
    }
    return 0;
}
