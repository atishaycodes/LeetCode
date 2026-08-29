class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            if(mpp.count(target-nums[i])){
                return {mpp[target-nums[i]], i  };
            }
            mpp[nums[i]] = i;
        }
        return {};
        
    }
};