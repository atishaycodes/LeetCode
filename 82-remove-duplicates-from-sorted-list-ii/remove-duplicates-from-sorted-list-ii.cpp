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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;

        unordered_map<int, int> mpp;
        ListNode* curr = head;
        vector<int> a;
        vector<int> b;
        while(curr){
            mpp[curr->val]++;
            a.push_back(curr->val);
            curr = curr->next;

        }
        for(int i=0; i<a.size(); i++){
            if(mpp[a[i]]==1) {
                b.push_back(a[i]);
            }
        }
        if(b.size()==0){
            return NULL;
        }
        ListNode* res = new ListNode(b[0]);
        ListNode* ans = res;
        for(int i=1; i<b.size(); i++){
            ListNode* temp = new ListNode(b[i]);
            res->next = temp;
            res = res->next;
        }
        return ans;

    }
};