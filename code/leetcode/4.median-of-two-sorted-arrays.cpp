/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (24.06%)
 * Total Accepted:    315.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median_num=0.0;
        int dan_shuang=0;
        int all_length=nums1.size()+nums2.size();
        if(all_length%2==0)
            dan_shuang=1;
        vector<double>nums3;
        int num1=0;
        int num2=0;
        
        for(int i=0;i<all_length/2+1;i++)
        {
            if(num1==nums1.size())
            {
                nums3.push_back(nums2[num2]);
                num2++;
            }
            else if(num2==nums2.size())
            {
                nums3.push_back(nums1[num1]);
                num1++;
            }
            else if(nums1[num1]>=nums2[num2])
            {
                nums3.push_back(nums2[num2]);
                num2++;
            }
            else if(nums2[num2]>=nums1[num1])
            {
                nums3.push_back(nums1[num1]);
                num1++;
            }
        }     
        if(dan_shuang==0)
            median_num= nums3[all_length/2];
        else
        {
            median_num=(double)((nums3[nums3.size()-1]+nums3[nums3.size()-2])/2);
        }
        return median_num;//(double)((nums3[nums3.size()-1]+nums3[nums3.size()-2])/2);
    }
};
