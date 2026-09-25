class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;

        double y = power(x, n / 2);

        if (n % 2 == 0)
            return y * y;
        else
            return y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0)
            return 1 / power(x, -N);

        return power(x, N);
    }
};