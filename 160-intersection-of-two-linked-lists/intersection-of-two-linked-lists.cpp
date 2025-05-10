/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* headA) {
        int len = 0;
        ListNode* node = headA;
        while (node) {
            len++;
            node = node->next;
        }
        return len;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        if (len1 > len2) {
            int temp = len1 - len2;
            while (temp--)
                node1 = node1->next;
            while (node1 != node2) {
                node1 = node1->next;
                node2 = node2->next;
            }
        } else {
            int temp = len2 - len1;
            while (temp--)
                node2 = node2->next;
            while (node1 != node2) {
                node1 = node1->next;
                node2 = node2->next;
            }
        }
        return node1;
    }
};