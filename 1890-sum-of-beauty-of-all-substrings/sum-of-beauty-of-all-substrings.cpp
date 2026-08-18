class Solution {
public:
    int beautySum(string s) {
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        vector<int> count(26, 0);

        for(int j = i; j < s.size(); j++) {
            count[s[j] - 'a']++;

            int mx = 0;
            int mn = INT_MAX;

            for(int k = 0; k < 26; k++) {
                if(count[k] > 0) {
                    mx = max(mx, count[k]);
                    mn = min(mn, count[k]);
                }
            }

            ans += mx - mn;
        }
    }

    return ans;
}
};