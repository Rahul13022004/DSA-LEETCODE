class Solution {
public:
    // Helper function to reverse nodes from start to (but not including) end
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* nextpt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextpt;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to the node before the 'left' position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // start is the first node to be reversed
        ListNode* start = prev->next;
        // end is the node after the last node to be reversed
        ListNode* end = start;
        for (int i = left; i <= right; ++i) {
            end = end->next;
        }

        // Reverse and reconnect
        prev->next = reverse(start, end);
        start->next = end;

        return dummy.next;
    }
};
