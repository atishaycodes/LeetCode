class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMostK(nums, k) - AtMostK(nums, k-1);
    }
    int AtMostK(vector<int>& nums, int k){
        int n= nums.size();
        int l=0;
        int cnt=0;
        unordered_map<int, int> mpp;
        for(int r=0; r<n; r++){
            mpp[nums[r]]++;
            if(mpp.size()<=k){
                cnt= cnt+ (r-l+1);
            }
            else{
                while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
                }
                cnt+=(r-l+1);

            }

            
        }
        return cnt;
    }
};