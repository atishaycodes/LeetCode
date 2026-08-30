class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int minIndex=-1;
        int maxIndex = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxx){
                maxIndex=i;
            }
            if(nums[i]==minn){
                minIndex = i;
            }
        }
        int front = max(minIndex, maxIndex) + 1;
        int back = n - min(minIndex, maxIndex);
        int both = min(minIndex, maxIndex) + 1 + n - max(minIndex, maxIndex);

        return min({front, both, back});
        
        
    }
};