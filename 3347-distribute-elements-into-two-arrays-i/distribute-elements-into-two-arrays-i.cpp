class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int k=0; int j=0;

        for(int i=2; i<nums.size(); i++){

            if(arr1[j] > arr2[k]){
                arr1.push_back(nums[i]);
                j++;
            }
            else{
                arr2.push_back(nums[i]);
                k++;
            }
        }
        for(auto it : arr2){
            arr1.push_back(it);
        }
        return arr1;
    }
};