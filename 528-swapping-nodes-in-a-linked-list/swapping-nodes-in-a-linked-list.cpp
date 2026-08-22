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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int i=1;
        while(curr && i<k){
            curr = curr->next;
            i++;
        }
        ListNode* slow=head;
        ListNode* fast = head;

        for(int j=0; j<k; j++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow= slow->next;
        }
        int temp = curr->val;
        curr->val = slow->val;
        slow->val = temp;

        return head;
    }
};