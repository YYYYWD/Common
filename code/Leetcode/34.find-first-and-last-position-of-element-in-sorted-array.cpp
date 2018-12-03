/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.34%)
 * Total Accepted:    240.4K
 * Total Submissions: 743.1K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        int left=0;
        int right=nums.size()-1;
         int mid;
        while(left<right)//求第一个等于target的位置
        {
           mid=left+(right-left)/2;
           if(nums[mid]<target)
                left=mid+1;
            else
                right=mid;
        }
        if(nums[left]!=target)
            return {-1,-1};
        int t1=left;
        
        right=nums.size()-1;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]<=target)
                left=mid+1;
            else
                right=mid;
        }
        int t2=0;
        if((left-1)>=0&&nums[left-1]==target&&nums[left]!=target)
            t2=left-1;
        else if((left-1)>=0&&nums[left]==target)
            t2=left;
        return {t1,t2};
        

    }
};
