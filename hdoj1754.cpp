/**
 * hdoj 1754 - I Hate It
 * http://acm.hdu.edu.cn/showproblem.php?pid=1754
 *
 * basic implementation of segment tree
 *
 * @author wangdai
 * @date 2014-12-22
 */

#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
    int val;
    int left;
    int right;
};

Node nodes[600000];
int score[200005];
int N, M, A, B, C;
char tmp_str[20];

inline int lchildid(int nodeid)
{
    return 2*nodeid;
}

inline int rchildid(int nodeid)
{
    return 2*nodeid + 1;
}

int build_segtree(int nodeid, int left, int right)
{
    Node *node = &nodes[nodeid];
    node->left = left;
    node->right = right;
    if (left == right) {
        node->val = score[left];
        return score[left];
    }
    int mid = (left + right) / 2;
    int lmax = build_segtree(lchildid(nodeid), left, mid);
    int rmax = build_segtree(rchildid(nodeid), mid+1, right);
    int cmax = max(lmax, rmax);
    node->val = cmax;
    return cmax;
}

int build_segtree()
{
    return build_segtree(1, 1, N);
}

int query_segtree(int nodeid, int left, int right)
{
    Node *node = &nodes[nodeid];
    int node_mid = (node->left + node->right) / 2;
    if (left == node->left && right == node->right) {
        return node->val;
    } else if (right <= node_mid) {
        return query_segtree(lchildid(nodeid), left, right);
    } else if (left > node_mid) {
        return query_segtree(rchildid(nodeid), left, right);
    } else {
        return max(query_segtree(lchildid(nodeid), left, node_mid),
                   query_segtree(rchildid(nodeid), node_mid+1, right));
    }
}

int query_segtree(int left, int right)
{
    return query_segtree(1, left, right);
}

void update_segtree(int nodeid, int left, int right, int stuid, int update_val)
{
    Node *node = &nodes[nodeid];
    if (stuid == left && left == right) {
        node->val = update_val;
        return;
    }
    int node_mid = (node->left + node->right) / 2;
    if (stuid <= node_mid) {
        update_segtree(lchildid(nodeid), left, node_mid, stuid, update_val);
    } else {
        update_segtree(rchildid(nodeid), node_mid+1, right, stuid, update_val);
    }
    node->val = max(nodes[lchildid(nodeid)].val, nodes[rchildid(nodeid)].val);
}

void update_segtree(int stuid, int update_val)
{
    update_segtree(1, 1, N, stuid, update_val);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &N, &M) >= 0) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &score[i]);
        }
        build_segtree();
        while (M--) {
            scanf("%s%d%d", tmp_str, &A, &B);
            C = tmp_str[0];
            if (C == 'Q') {
                printf("%d\n", query_segtree(A, B));
            } else if (C == 'U') {
                score[A] = B;
                update_segtree(A, B);
            }
        }
    }
    return 0;
}
