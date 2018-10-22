/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.24%)
 * Total Accepted:    615.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);
         ListNode* start;
         start=l3;
        ListNode *p,*q;
        p=l1;
        q=l2;
        l3->val=0;
        while(p!=NULL&&q!=NULL)
        {
            bool is_jin=0;
            int num=0;
            num=p->val+q->val;
            if(num>10)
            {
                l3->val=num-10;
                is_jin=1;
            }
            else
                l3->val=num;
            l3->next=new ListNode(0);
            l3=l3->next;
            l3->val=0;
            if(is_jin)
                l3->val=l3->val+1;
            p=p->next;
            q=q->next;
        }
        if(p)
        {
            while(q)
            {
                l3->val=q->val;
                l3->next=new ListNode(0);
                l3=l3->next;
                q=q->next;
            }
        }
        if(q)
        {
            while(p)
            {
                l3->val=p->val;
                l3->next=new ListNode(0);
                l3=l3->next;
                p=p->next;
            }
        }
        return l3;
    }
};
