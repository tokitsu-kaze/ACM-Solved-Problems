#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int st[MAX],top,res[MAX],n;
int ck()
{
	int i,cnt;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(') cnt++;
		else cnt--;
	}
	if(cnt!=0) return 0;
	return 1;
}
int gao()
{
	int i,ans;
	top=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(') st[top++]=i;
		else
		{
			if(top && s[st[top-1]]=='(')
			{
				res[st[--top]]=1;
				res[i]=1;
			}
			else st[top++]=i;
		}
	}
	ans=1;
	if(top)
	{
		if(top==n)
		{
			ans=1;
			while(top) res[st[--top]]=1;
		}
		else
		{
			ans=2;
			while(top) res[st[--top]]=2;
		}
	}
	else ans=1;
	return ans;
}
int main()
{
	int T,i,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if(!ck())
		{
			puts("-1");
			continue;
		}
		ra=gao();
		reverse(s+1,s+1+n);
		rb=gao();
		reverse(res+1,res+1+n);
		if(ra<rb)
		{
			reverse(s+1,s+1+n);
			gao();
		}
		printf("%d\n",min(ra,rb));
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
1
6
))()((
*/
