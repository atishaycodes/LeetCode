class Solution {
    private:
    void solve(vector<int>& nums, vector<vector<int>> &res, int &n, vector<int> temp, unordered_set<int> st){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, res, n, temp, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> st;
        int n= nums.size();
        solve(nums, res, n, temp, st);
        return res;
    }
};