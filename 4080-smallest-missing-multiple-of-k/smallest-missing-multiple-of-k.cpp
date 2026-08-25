class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i=k; ; i+=k){
            bool flag = false;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]==i){
                    flag = true;
                    break;
                }
            }
            if(!flag) return i;
        }
        return 0;
    }
};