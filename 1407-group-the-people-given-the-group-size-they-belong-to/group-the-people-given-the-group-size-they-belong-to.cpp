class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        int n = groupSizes.size();

        unordered_map<int, vector<int>> mpp;

        for(int i=0; i<n; i++){
            int reqSize = groupSizes[i];
            mpp[reqSize].push_back(i);

            if(mpp[reqSize].size()==reqSize){
                groups.push_back(mpp[reqSize]);
                mpp[reqSize].clear();
            }
        }
        return groups;
    }
};