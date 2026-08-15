class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool y = 1;
        for(int i=0; i<nums.size(); i++){
            x^=nums[i];
            if(nums[i]!=0) y = 0;  
        }
        if(y) return 0;
        if(x!=0)  return nums.size();
        
        else return nums.size()-1;
        
    }
};