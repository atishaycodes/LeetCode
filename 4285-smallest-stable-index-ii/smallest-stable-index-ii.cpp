class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        int maxx = INT_MIN;
        for(int i=0; i<n; i++){
            maxx = max(nums[i], maxx);
            prefix[i] = maxx;
        }

        int minn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            minn = min(nums[i], minn);
            suffix[i] = minn;
        }

        for(int i=0; i<n; i++){
            if(prefix[i]-suffix[i] <= k){
                return i;
            }
        }
        return -1;
    }
};