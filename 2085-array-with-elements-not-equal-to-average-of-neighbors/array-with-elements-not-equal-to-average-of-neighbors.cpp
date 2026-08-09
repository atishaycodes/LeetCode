class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n);


        sort(nums.begin(),nums.end());
        int i=0, j=0;
        while(j<n){
            res[j] = nums[i];
            i++; j+=2;
        }
        j=1;
        while(i<n && j<n){
            res[j]=nums[i];
            j+=2; i++;
        }
        return res;


    }
};