/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.28%)
 * Total Accepted:    330.9K
 * Total Submissions: 1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<nums[right])//搜索右边
            {
                
                if(nums[mid]<=target&&target<=nums[right])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
            }
            else if(nums[mid]>nums[right])//搜索左边
            {
             
                if(nums[left]<=target&&target<=nums[mid])
                {
                    right=mid;
                }
                else
                {
                    left=mid+1;
                }
            }
        }
        if(nums[left]==target||nums[right]==target)
            return left;
        return -1;

        
    }
};
