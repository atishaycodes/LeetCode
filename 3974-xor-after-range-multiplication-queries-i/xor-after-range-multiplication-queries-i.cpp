class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        const int MOD = 1e9+7;
        using ll = long long;
        for(int i=0; i<n; i++){
           ll idx = queries[i][0];
           ll r = queries[i][1];
           ll v = queries[i][3];
           ll k = queries[i][2];
           while(idx<=r){
            nums[idx]=(nums[idx]*v)%MOD;
            idx+=k;
           }
        }
        int x=0;
        for(ll num : nums){
            x^=num;
        }
        return x;
    }
};