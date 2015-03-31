/**
 * leetcode 189 - Rotate Array
 * https://leetcode.com/problems/rotate-array/
 *
 * do NOT try to shift elements in array, it's inefficient when array is large
 *
 * @author wangdai
 * @date 2015-03-31
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/* recursive solution, O(1) space, about O(n) time */
void rotate(int nums[], int n, int k) {
    k = k % n;
    if (k == 0) return;
    if (k <= n/2) {
        for (int i = 0; i < k; i++) {
            swap(nums[i], nums[i+n-k]);
        }
        rotate(&nums[k], n-k, k);
    } else {
        for (int i = n-1; i >= k; i--) {
            swap(nums[i], nums[i-k]);
        }
        rotate(nums, k, k+k-n);
    }
}

/* dequeue solution, O(n) space, O(n+k) time */
void rotate2(int nums[], int n, int k) {
    if (n <= 1 || k == 0) return;
    struct List {
        int val;
        List *prev;
        List *next;
    } *head, *tail;
    head = new List;
    tail = head;
    head->val = nums[n-1];
    head->next = NULL;
    head->prev = NULL;
    for (int i = n-2; i >= 0; i--) {
        List *p = new List;
        p->val = nums[i];
        p->next = head;
        p->prev = NULL;
        head->prev = p;
        head = p;
    }
    k = k % n;
    for (int i = 0; i < k; i++) {
        List *tt = tail->prev;
        tt->next = NULL;
        tail->prev = NULL;
        tail->next = head;
        head->prev = tail;
        head = tail;
        tail = tt;
    }
    int i = 0;
    for (List *p = head; p != NULL; p = p->next) {
        nums[i++] = p->val;
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6};
    int a2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    rotate(a, 6, 1); /* {6,1,2,3,4,5} */
    rotate2(a2, 13, 17); /* {10,11,12,13,1,2,3,4,5,6,7,8,9} */
    return 0;
}
