#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],st[MAX];
int main()
{
	int n,i,top,ok;
	scanf("%s",s+1);
	n=strlen(s+1);
	top=0;
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(s[i]==']')
		{
			if(top && st[top-1]=='[') top--;
			else ok=0;
		}
		else if(s[i]=='>')
		{
			if(top && st[top-1]=='<') top--;
			else ok=0;
		}
		else if(s[i]==')')
		{
			if(top && st[top-1]=='(') top--;
			else ok=0;
		}
		else st[top++]=s[i];
		if(!ok) break;
	}
	if(ok && top==0) puts("Yes");
	else puts("No");
	return 0;
}
