class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* dup = curr->next;
                curr->next = curr->next->next;
                delete dup;  // free memory of duplicate node
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
