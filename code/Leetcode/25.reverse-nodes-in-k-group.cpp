/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (33.94%)
 * Total Accepted:    151.5K
 * Total Submissions: 446.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
   ListNode* reverseOneGroup(ListNode* head,ListNode *end)
    {
        ListNode *prev=head->next;
        ListNode *pcur=prev->next;
        while(pcur!=end)
        {
            prev->next=pcur->next;
            pcur->next=head->next;
            head->next=pcur;
            pcur=prev->next;
        }
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head||k==1)return head;
        ListNode *d=new ListNode(-1);
        ListNode *pre=d,*cur=head;
        d->next=head;
        int i=0;
        while(cur)
        {
            ++i;
            if(i%k==0)
            {
                pre=reverseOneGroup(pre,cur->next);
                cur=pre->next;
            }
            else
                cur=cur->next;
        }
        return d->next;

    }
};
