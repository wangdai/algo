#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, K;
int postOrder[40];
int inOrder[40];
int result[40];

struct Node {
    int value;
    Node *left;
    Node *right;
};

int findPos(int key)
{
    for (int i = 0; i < N; i++) {
        if (inOrder[i] == key) {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int value, int ll, int rr)
{
    Node *nnode = new Node;
    nnode->value = value;
    int pos = findPos(value);
    if (pos < rr) {
        nnode->right = buildTree(postOrder[--K], pos+1, rr);
    }
    else {
        nnode->right = NULL;
    }
    if (ll < pos) {
        nnode->left = buildTree(postOrder[--K], ll, pos-1);
    }
    else {
        nnode->left = NULL;
    }
    return nnode;
}

int main()
{
    cin >> N;
    K = N;
    for (int i = 0; i < N; i++) {
        cin >> postOrder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inOrder[i];
    }

    Node *root = buildTree(postOrder[--K], 0, N-1);
    queue<Node *> q;
    q.push(root);
    int j = 0;
    while (!q.empty()) {
        Node *fat = q.front();
        q.pop();
        result[j++] = fat->value;
        if (fat->left != NULL) {
            q.push(fat->left);
        }
        if (fat->right != NULL) {
            q.push(fat->right);
        }
    }

    // 为了奇怪的输出要求所以先把结果存一数组里了
    for (int i = 0; i < j; i++) {
        cout << result[i];
        if (i < j - 1) {
            cout << " ";
        }
    }

    return 0;
}
