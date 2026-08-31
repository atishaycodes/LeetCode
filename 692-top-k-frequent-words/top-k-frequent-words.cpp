class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue < pair<int, string> , vector < pair<int, string>>,
            greater<pair<int, string>>> heap;
        int n = words.size();

        unordered_map<string, int> mpp;

        for (string s : words) {
            mpp[s]++;
        }


        for (auto [str, val] : mpp) {
            heap.push({-val, str});
        }

        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
};