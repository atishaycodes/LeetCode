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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2==NULL) return NULL;
        if(list1 == NULL && list2!= NULL) return list2;
        if(list1 != NULL && list2== NULL) return list1;
        vector<int> List;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                List.push_back(curr2->val);
                curr2=curr2->next;
                continue;

            }
            else if(curr1->val < curr2->val){
                List.push_back(curr1->val);
                curr1=curr1->next;
                continue;
            }
            else{
                List.push_back(curr1->val);
                List.push_back(curr2->val);
                curr1=curr1->next;
                curr2=curr2->next;
            }

        }
            while(curr1){
                List.push_back(curr1->val);
                curr1=curr1->next;
            }
            while(curr2){
                List.push_back(curr2->val);
                curr2=curr2->next;
            }
            ListNode* head = new ListNode(List[0]);
            ListNode* temp = head;
            for(int i=1; i<List.size(); i++){
                ListNode* newNode = new ListNode(List[i]);
                temp->next = newNode;
                temp= temp->next;
            }
            return head;
        
    }
};