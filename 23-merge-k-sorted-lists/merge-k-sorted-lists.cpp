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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of each list into the priority queue
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};