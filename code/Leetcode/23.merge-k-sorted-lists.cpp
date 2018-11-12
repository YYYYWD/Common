/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (30.96%)
 * Total Accepted:    291.4K
 * Total Submissions: 938.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
       if(lists.size()==0)
            return NULL;
        int k=lists.size();
        while(k>1)
        {
            int n=(k+1)/2;
            for(int i=0;i<k/2;i++)
                lists[i]=merge2List2(lists[i],lists[i+n]);
            k=n;
        }
        return lists[0];
    }
    ListNode*merge2List2(ListNode*l1,ListNode*l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *ans1=new ListNode(-1);
        ListNode *ans = ans1;  
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                ans->next=l1;
                l1=l1->next;
            }
            else
            {
                ans->next=l2;
                l2=l2->next;
            }
            ans=ans->next;
        }
        if(l1==NULL)ans->next=l2;
        else if(l2==NULL)
            ans->next=l1;
        return ans1->next;
    }
};
