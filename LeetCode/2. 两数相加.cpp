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
        string a,b;
        while(l1!=NULL)
        {
            a+=l1->val+'0';
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            b+=l2->val+'0';
            l2=l2->next;
        }
        string res;
        int i=0,j=0;
        int add=0;
        int n=(int)a.size();
        int m=(int)b.size();
        while(1)
        {
            if(i>=n&&j>=m)
            {
                if(add) res+=add+'0';
                break;
            }
            int now=add;
            if(i<n) now+=a[i]-'0';
            if(j<m) now+=b[j]-'0';
            add=now/10;
            now%=10;
            res+=now+'0';
            i++;
            j++;
        }
        ListNode* head;
        head=new ListNode(0);
        ListNode* now=head;
        for(i=0;i<(int)res.size();i++)
        {
            now->next=new ListNode(res[i]-'0');
            now=now->next;
        }
        return head->next;
    }
};
