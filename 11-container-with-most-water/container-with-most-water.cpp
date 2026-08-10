class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int h = 0;
        long long possible = 0;
        while(i<j){
            h = min(height[i], height[j]);
            long long width = j-i;
            long long area= (long long)h*width;
            if(area>possible) {
                possible = area;
            }
            if(height[i]>height[j]) {
                j--;
            }
            else{
                i++;
            }



        }
        return possible;
    }
};