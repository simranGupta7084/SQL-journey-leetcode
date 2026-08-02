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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* previousGroupEnd = head;

        // First group has one node, so begin from group size 2
        int groupSize = 2;

        while (previousGroupEnd->next != nullptr) {
            ListNode* groupStart = previousGroupEnd->next;
            ListNode* temp = groupStart;

            int actualSize = 0;

            // Count nodes in the current group
            while (temp != nullptr && actualSize < groupSize) {
                temp = temp->next;
                actualSize++;
            }

            // temp is the node after the current group
            ListNode* nextGroupStart = temp;

            if (actualSize % 2 == 0) {
                // Reverse the current group
                ListNode* previous = nextGroupStart;
                ListNode* current = groupStart;

                while (current != nextGroupStart) {
                    ListNode* nextNode = current->next;

                    current->next = previous;
                    previous = current;
                    current = nextNode;
                }

                // Connect previous group to reversed group
                previousGroupEnd->next = previous;

                // Old groupStart becomes the new group end
                previousGroupEnd = groupStart;
            }
            else {
                // Do not reverse; move to the group's last node
                for (int i = 0; i < actualSize; i++) {
                    previousGroupEnd = previousGroupEnd->next;
                }
            }

            groupSize++;
        }
        return head;


        
    }
};