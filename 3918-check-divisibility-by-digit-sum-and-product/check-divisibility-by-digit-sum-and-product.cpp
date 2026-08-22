class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0; int prod=1;
        int temp = n;
        while(temp > 0){
            int dig = temp%10;
            sum+=dig;
            prod*=dig;
            temp = temp/10;
        }
        int T = sum+prod;
        return n%T==0;
    }
};