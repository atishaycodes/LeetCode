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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        stack<int> st;
        vector<int> list;
        while(curr){
            list.push_back(curr->val);
            curr=curr->next;
        }
        vector<int> res(list.size());
        for(int i=list.size()-1; i>=0; i--){
            while(!st.empty() && list[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                res[i]=0;
                st.push(list[i]);
            }
            else{
                res[i] = st.top();
                st.push(list[i]);
            }
        }
        return res;
    }
};