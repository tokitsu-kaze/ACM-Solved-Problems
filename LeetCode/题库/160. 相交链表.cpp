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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *res=NULL;
        map<uintptr_t,int> mp;
        
        while(headA)
        {
        	mp[(uintptr_t)headA]=1;
        	headA=headA->next;
		}
        while(headB)
        {
        	if(mp.count((uintptr_t)headB))
        	{
        		res=headB;
        		return res;
			}
        	headB=headB->next;
		}
		return res;
    }
};
