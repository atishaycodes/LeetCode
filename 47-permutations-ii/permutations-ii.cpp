class Solution {
    private:
    void solve(vector<int>& nums, set<vector<int>> &res, int &n, vector<int> temp, vector<bool> used){
        if(temp.size()==n){
           res.insert(temp);
            return;
        }
        for(int i=0; i<n; i++){
                if(used[i]==true){
                    continue;
                }
                temp.push_back(nums[i]);
                used[i] = true;
                solve(nums, res, n, temp, used);
                temp.pop_back();
                used[i]=false;
            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> temp;
        int n= nums.size();
        vector<bool> used(n, false);
        
        solve(nums, res, n, temp, used);
        for(auto &it: res){
            ans.push_back(it);
        }
        return ans;
    }
};