class Solution {
public:
    int beautySum(string s) {
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        vector<int> count(26, 0);

        for(int j = i; j < s.size(); j++) {
            count[s[j] - 'a']++;

            int mx = *max_element(count.begin(), count.end());
            int mn = INT_MAX;
            for(int x:count){
                if(x>0 && x < mn ){
                    mn = x;
                }
            }
            ans += mx - mn;
        }
    }

    return ans;
}
};