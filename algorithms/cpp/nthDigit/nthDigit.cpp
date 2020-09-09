// https://leetcode.com/problems/nth-digit/
// Author : Robin Chen
// Date   : 2017.07.12

/********************************************************************************** 
* 
* Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
*
* Note:
* n is positive and will fit within the range of a 32-bit signed integer (n < 231).
*               
**********************************************************************************/

// 思路
// 每种数位的数，数量分别为 9，90，900... 
// 先确认数位数，然后对应到该数字就可以了

class Solution {
public:
    int findNthDigit(int n) {
        long p = 0, count = 1, num = 9, plast = 0, q = 1;
        while(n > p){
            plast = p;
            p = p + num*count;
            count++;
            num *= 10;
            q *= 10;
        }
        q /= 10; count -= 1; 
        long start = q + (n - plast - 1)/count;
        int pos = (n - plast - 1)%count;

        long len = 0, mod = 1;
        for (int i = 1; i <= start; i*=10, len++);
        for (int i = 1; i < len - pos; i++, mod *= 10);
        int result = start/mod%10;

        return result;
    }
};

// Runtime: 3 ms
// Memory Usage: N/A