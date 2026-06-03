#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int n;
char st[MAX];
int work(char *s)
{
	int i,top;
	top=0;
	for(i=1;i<=n;i++)
	{
		st[top++]=s[i];
		if(top>=3)
		{
			if(st[top-3]=='A' && st[top-2]=='B' && st[top-1]=='C') top-=3;
			if(st[top-3]=='B' && st[top-2]=='C' && st[top-1]=='A') top-=3;
			if(st[top-3]=='C' && st[top-2]=='A' && st[top-1]=='B') top-=3;
		}
	}
	for(i=0;i<top;i++) s[i]=st[i];
	return top;
}
char s[MAX],t[MAX];
int main()
{
	int lens,lent,i,tot,ok;
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	lens=work(s);
	lent=work(t);
	ok=1;
	if(lens!=lent) ok=0;
	for(i=0;i<lens;i++)
	{
		if(s[i]!=t[i]) ok=0;
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}
/*
发现 xabc -> abcx，反过来也成立。
所以abc可以随意移动，转化成消消乐，用栈维护。
bca和cab同理。 
*/
