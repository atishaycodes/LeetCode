class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minn = INT_MAX;
        int maxx = 0;
        for(int i=0; i<n; i++){
            minn = min(minn, prices[i]);
            maxx = max( maxx, prices[i]-minn);
        }
        return maxx;
    }
};