#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
char s[MAX];
int main()
{
	int q,op,cnt,now,n,pre;
	char ch[3];
	scanf("%d",&q);
	pre=n=cnt=now=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%s",ch);
			s[++n]=ch[0];
			if(s[n]=='(') now++;
			else now--;
			if(pre==0 && now==-1) cnt++;
		}
		else
		{
			if(s[n]=='(') now--;
			else now++;
			n--;
			if(now==0 && pre==-1) cnt--;
		}
		if(now==0 && cnt==0) puts("Yes");
		else puts("No");
		pre=now;
	}
	return 0;
}
