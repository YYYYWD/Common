/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.02%)
 * Total Accepted:    325.8K
 * Total Submissions: 814K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int length=nums.size();
    if(length==0)
        return 0;
    int left=0;
    int right=length-1;
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
            right=mid;
    }
    
    if(left==length-1&&nums[length-1]<target)
        return length;
    return left;
    }
};
