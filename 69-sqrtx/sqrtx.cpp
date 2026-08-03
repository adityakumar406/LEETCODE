class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        long long start = 1;
        long long end = x / 2;
        long long ans = 1;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
