/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.60%)
 * Total Accepted:    308.2K
 * Total Submissions: 917.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?   
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
//我写的垃圾算法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        ListNode*start=head;
        int num=1;
        while(start->next!=NULL)
        {
              num++;
              start=start->next;
        }
        if (num==1)
            return NULL;
        if (num==n)
        {
            head=head->next;
            return head;
        }
        start=head;

        for(int i=0;i<num-n-1;i++)
        {
            start=start->next;
        }
        if(start->next->next==NULL)
            start->next=NULL;
        else
            start->next=start->next->next;
        return head;
    }
    
    /*ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        

        ListNode *D=new ListNode(0);
        D->next=head;
        ListNode *first = D;
        ListNode *second =D;
        int n1=n;
        while(n1--)
        {
            first=first->next;
        }
        while(first->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        if(second->next==head)
        {
            head=head->next;
            return head;
        }
        second->next=second->next->next;
        return head;

    }*/
};
