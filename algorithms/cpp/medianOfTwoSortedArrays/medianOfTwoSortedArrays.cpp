// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Robin Chen
// Date   : 2018.3.24

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0
*
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2 + 3)/2 = 2.5
*               
**********************************************************************************/

// 先写个傻子也会的(m+n)log(m+n)的解法作对比

class Solution {
public:
       
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int len = nums1.size();
        if (len%2==0) return (nums1[len/2] + nums1[len/2-1])/2.0;
        else return nums1[len/2];
    }
};

// 运行结果：
// Accepted	85m		12.76%
// 显然这么干是不对的

/**********************************************************************************/

// 思路1：设较长数组为A，较短数组为B
// 从A的中值开始，用二分查找搜索它在B中的index
// 随后用两个index的和与真正的中值比较，更新搜索的范围
// 随后依然是，在更新后的范围中，找长数组的中值在短数组中的位置
// 因此需要两个接口，一个找index的二分查找，一个找前数组在后数组中index的函数
// 而且这个函数传递的参数很多

class Solution {
public:
    int FindIndexInArray(vector<int> a, int n, int low, int high)
    {
        while(low <= high)
        {
            int mid = (low + high)/2;
            if (a[mid] == n) return mid;
            else if (a[mid] > n) high = mid-1;
            else if (a[mid] < n) low = mid+1;
        }
        return low;
    
    }
    
    double findMedianInShorterArray(vector<int>& nums1, int n1, int low1, int high1, vector<int>& nums2, int n2, int low2, int high2)
    {
        int mid1 = low1 + (high1 - low1)/2;
        int indexIn2 = FindIndexInArray(nums2, nums1[mid1], low2, high2);

        if(mid1 + indexIn2 == (n1 + n2)/2){
            if((n1 + n2)%2 == 1)
                return nums1[mid1];
            else{
                int prev;
                if(mid1 == 0) prev = nums2[indexIn2-1];
                else if(indexIn2 == 0) prev = nums1[mid1-1];
                else prev = nums1[mid1-1] > nums2[indexIn2-1] ? nums1[mid1-1] : nums2[indexIn2-1];

                return (nums1[mid1]+prev)/2.0;
            }
        }
        else if(mid1 + indexIn2 < (n1 + n2)/2){
            low1 = mid1 + 1;
            low2 = indexIn2;
            if ( high1 - low1 > high2 - low2 )
                return findMedianInShorterArray(nums1, n1, low1, high1, nums2, n2, low2, high2);
            else return findMedianInShorterArray(nums2, n2, low2, high2, nums1, n1, low1, high1);
        }
        else{
            high1 = mid1-1;
            high2 = indexIn2 - 1;
            if ( high1 - low1 > high2 - low2 )
                return findMedianInShorterArray(nums1, n1, low1, high1, nums2, n2, low2, high2);
            else return findMedianInShorterArray(nums2, n2, low2, high2, nums1, n1, low1, high1);
        }
    } 
       
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;

        if ( len1==0 && len2==0 ) return 0.0;

        if ( len1==0 ) return len2%2==1 ? nums2[len2/2] : (nums2[len2/2-1] + nums2[len2/2])/2.0;
        if ( len2==0 ) return len1%2==1 ? nums1[len1/2] : (nums1[len1/2-1] + nums1[len1/2])/2.0;

        if (len1 > len2)
            return findMedianInShorterArray(nums1, len1, 0,len1-1, nums2, len2, 0,len2-1);
        else
            return findMedianInShorterArray(nums2, len2, 0,len2-1, nums1, len1, 0,len1-1);
    }
};

// 运行结果：
// Accepted	101ms	4.24%
// ？？？我嘞个擦？为什么比排序还慢？STL这么吊的吗？
// 我的自信心受到了打击

// 思路2：标准答案
// 感觉分析复杂度的话没有太大变化，但是思路清晰很多，程序整洁很多

class Solution {
public:   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 > len2){
            return findMedianSortedArrays(nums2, nums1);
        }
    
        int iMin = 0, iMax = len1, harf = (len1 + len2 + 1)/2;
        while(iMin <= iMax){
            int i = (iMin + iMax)/2;
            int j = harf - i;
            if(i < iMax && nums2[j-1] > nums1[i])
                iMin = i+1;
            else if(i > iMin && nums1[i-1] > nums2[j])
                iMax = i - 1;
            else{
                int maxLeft = 0;
                if(i == 0) maxLeft = nums2[j-1];
                else if(j == 0) maxLeft = nums1[i-1];
                else maxLeft = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
                if((len1 + len2)%2 ==1) return maxLeft;
            
                int minRight = 0;
                if(i == len1) minRight = nums2[j];
                else if(j == len2) minRight = nums1[i];
                else minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            
                return(maxLeft + minRight)/2.0;
            }
        }
    }
    
};

// 运行结果：
// Accepted		71ms	50.74%