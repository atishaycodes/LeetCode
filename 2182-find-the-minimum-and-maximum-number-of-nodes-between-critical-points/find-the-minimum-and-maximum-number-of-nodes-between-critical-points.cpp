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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        long long i=1;

        while(next!=NULL){
            if(prev->val > curr-> val && next->val > curr->val){
                res.push_back(i);
            }
            else if(prev->val < curr-> val && next->val < curr->val){
                res.push_back(i);
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            next = next->next;
        }

       if(res.size()==0 || res.size()==1){
        return {-1,-1};
       }
       vector<int> ans;
        int minSum = INT_MAX;
        int maxx = INT_MIN;
        int minElement = INT_MAX;
       for(int i=1; i<res.size(); i++){
          minSum = min(res[i]-res[i-1], minSum);
       }

       maxx = *max_element(res.begin(), res.end());
       minElement = *min_element(res.begin(), res.end());

       ans.push_back(minSum);
       ans.push_back(maxx-minElement);

       

       return ans;


        
    }
};