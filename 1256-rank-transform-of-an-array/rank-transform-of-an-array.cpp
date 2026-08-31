class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std :: priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;

        int n= arr.size();

        for(int i=0; i<n; i++){
            heap.push({arr[i], i});
        }

        vector<int> ans(n, 0);
        int rank = 0;

        int prev = INT_MAX;

        while(!heap.empty()){
            auto [value, index] = heap.top();
            heap.pop();

            if(value!=prev){
                rank++;
                prev = value;
                
            }
            ans[index] = rank;
            
        }

        return ans;



        
        
    }
};