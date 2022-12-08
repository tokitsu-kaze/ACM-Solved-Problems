/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return NULL;
		ListNode *now,*pre,*newhead,*ppre;
		pre=head;
		now=pre;
		newhead=NULL;
		ppre=NULL;
		while(pre)
		{
			int cnt=0;
			while(now&&now->val==pre->val)
			{
				cnt++;
				now=now->next;
			}
			if(cnt==1)
			{
				if(!newhead)
				{
					newhead=pre;
					ppre=pre;
				}
				else
				{
					ppre->next=pre;
					ppre=pre;
				}
			}
			pre=now;
		}
		if(ppre) ppre->next=NULL;
		return newhead;
    }
};
