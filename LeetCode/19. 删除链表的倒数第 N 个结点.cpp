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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* now;
		now=head;
		int cnt=0;
		while(now)
		{
			cnt++;
			now=now->next;
		}
		n=cnt-n+1;
		if(n==1) return head->next;
		now=head;
		while(n>2)
		{
			now=now->next;
			n--;
		}
		now->next=now->next->next;
		return head;
    }
};
