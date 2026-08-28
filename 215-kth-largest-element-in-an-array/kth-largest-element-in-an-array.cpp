class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int i = 0; i < k; i++) {
            heap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            heap.push(nums[i]);
            heap.pop();
        }
        return heap.top();
    }
};