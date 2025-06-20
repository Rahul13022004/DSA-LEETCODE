class Solution {
public:
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reversell(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* mid = findmiddle(head);
        ListNode* second = reversell(mid->next);

        ListNode* first = head;
        ListNode* temp = second;

        while (temp) {
            if (first->val != temp->val)
                return false;
            first = first->next;
            temp = temp->next;
        }

        // Optional: Restore original list
        mid->next = reversell(second);

        return true;
    }
};
