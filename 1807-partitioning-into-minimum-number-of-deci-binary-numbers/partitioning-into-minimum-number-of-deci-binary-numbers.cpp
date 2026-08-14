class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int maxL;
        for(int i=0; i<len; i++){
            maxL = max(maxL, n[i]-'0');
        }
        return maxL;
    }
};