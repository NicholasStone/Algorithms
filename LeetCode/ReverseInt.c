//
// Created by Nicho on 2018/11/30 0030.
//

#include <stdint.h>

int reverse(int x) {
    int result = 0;
    while (x) {
        int pop = x % 10;
        x /= 10;
        if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && pop > 7))
            return 0;
        if (result < INT32_MIN / 10 || (result = INT32_MIN / 10 && pop < -8))
            return 0;
        result = result * 10 + x % 10;
    }

    return result;
}

//class Solution {
//        public:
//        int reverse(int x) {
//            int rev = 0;
//            while (x != 0) {
//                int pop = x % 10;
//                x /= 10;
//                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//                rev = rev * 10 + pop;
//            }
//            return rev;
//        }
//};

// fastest
//int reverse(int x) {
//    int y=0;
//    while(x)
//    {
//        int temp=y;
//        y=y*10+x%10;
//        if((y-x%10)/10!=temp)
//        {
//            return 0;
//        }
//        x/=10;
//    }
//    return y;
//}