class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0;
        int count = 0;
        int len = INT_MAX;
        string res = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1') {
                count++;
            }

            while (count == k) {

                int currLen = right - left + 1;

                if (currLen < len) {
                    len = currLen;
                    res = s.substr(left, currLen);
                }
                else if (currLen == len) {
                    string temp = s.substr(left, currLen);

                    if (temp < res) {
                        res = temp;
                    }
                }

                if (s[left] == '1') {
                    count--;
                }

                left++;
            }
        }

        return res;
    }
};