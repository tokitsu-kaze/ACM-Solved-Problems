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
    ListNode* middleNode(ListNode* head) {
        ListNode* now=head;
        int n=0;
        while(now)
        {
            n++;
            now=now->next;
        }
        n=n/2;
        now=head;
        while(n--)
        {
            now=now->next;
        }
        return now;
    }
};
