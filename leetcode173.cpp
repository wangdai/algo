/**
 * leetcode 173 - Binary Search Tree Iterator 
 * https://leetcode.com/problems/binary-search-tree-iterator/
 *
 * clean code and easy to understand
 *
 * @author wangdai
 * @date 2015-04-21
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root) {
        pushLeftPath(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = stk.top(); stk.pop();
        pushLeftPath(node->right);
        return node->val;
    }

private:
    void pushLeftPath(TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};

int main()
{
    TreeNode root(50);
    TreeNode c1(20);
    TreeNode c2(80);
    TreeNode cc1(10);
    TreeNode cc2(30);
    TreeNode cc3(75);
    TreeNode cc4(100);
    root.left = &c1;
    root.right = &c2;
    c1.left = &cc1;
    c1.right = &cc2;
    c2.left = &cc3;
    c2.right = &cc4;
    BSTIterator i = BSTIterator(&root);
    while (i.hasNext()) cout << i.next() << endl;
    return 0;
}
