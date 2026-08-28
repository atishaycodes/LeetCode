class Solution {
    private:
    void solve(vector<int>& nums, vector<vector<int>> &res, int &n, vector<int> temp){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(find(temp.begin(), temp.end(), nums[i])==temp.end()){
                temp.push_back(nums[i]);
                solve(nums, res, n, temp);
                temp.pop_back();
               
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n= nums.size();
        solve(nums, res, n, temp);
        return res;
    }
};