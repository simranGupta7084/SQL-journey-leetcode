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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrevious = &dummy;

        while (true) {
            // Find the kth node
            ListNode* kth = groupPrevious;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            // Fewer than k nodes remain
            if (kth == nullptr) {
                break;
            }

            // Node immediately after the current group
            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            while (current != groupNext) {
                ListNode* nextNode = current->next;

                current->next = previous;
                previous = current;
                current = nextNode;
            }

            // Connect the reversed group
            ListNode* oldGroupStart = groupPrevious->next;

            groupPrevious->next = kth;
            groupPrevious = oldGroupStart;
        }

        return dummy.next;
        
    }
};