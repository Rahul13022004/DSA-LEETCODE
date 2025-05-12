/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        temp = head;
        ListNode* prev = nullptr;
        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }
};