class Solution {
public:vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
        	
            for(int j=i+1;j<nums.size();j++)
            {
            	
                int start=j+1;
                int end=nums.size()-1;
                
                while(start<end)
                {
                    if(nums[i]+nums[j]+nums[start]+nums[end]==target)
                    {
                        vector<int>ans1;
                        ans1.push_back(nums[i]);
                        ans1.push_back(nums[j]);
                        ans1.push_back(nums[start]);
                        ans1.push_back(nums[end]);
                        ans.push_back(ans1);
                        start++;
                        end--;
                        while((start<end)&&nums[start]==nums[start-1])start++;
                        while((start<end)&&nums[end]==nums[end+1])end--;
                    }
                    else if(nums[i]+nums[j]+nums[start]+nums[end]<target)
                        start++;
                    else if(nums[i]+nums[j]+nums[start]+nums[end]>target)
                        end--;
                    
                }
                   while((j+1)<nums.size()&&nums[j+1]==nums[j])j++;
            }
            while((i+1)<nums.size()&&nums[i+1]==nums[i])i++;
        }
     return ans;
    }
};