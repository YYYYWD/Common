/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.82%)
 * Total Accepted:    436K
 * Total Submissions: 995K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*head=new ListNode(0);
        ListNode*p1=l1;
        ListNode*p2=l2;
        if(p1==NULL)
        {
            return p2;
        }
        else if(p2==NULL)
        {
            return p1;
        }
        if(p1->val>=l2->val)
        {
            head=p2;
            p2=p2->next;
        }
        else
          {
            head=p1;
            p1=p1->next;
          }  
          ListNode*head1=head;
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->val<=p2->val)
            {
                head->next=p1;
                p1=p1->next;
                head=head->next;
            }
            else
            {
                head->next=p2;
                p2=p2->next;
                head=head->next;
            }
        }
        if(p1==NULL)
        {
            head->next=p2;
        }
        else if(p2==NULL)
        {
            head->next=p1;
        }
        return head1;
    }
};
