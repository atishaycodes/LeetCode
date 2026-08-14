class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxL = 0;
        vector<int> a(26,0);
        int l=0;
        int n = s.size();
        for(int r=0; r<n; r++){
            char c = s[r];
            a[c-'a']++;
            while(a[c-'a'] > 2){
                char d = s[l];
                a[d-'a']--;
                l++;
            }
            maxL = max(maxL, r-l+1);
        }
        return maxL;
    }
};