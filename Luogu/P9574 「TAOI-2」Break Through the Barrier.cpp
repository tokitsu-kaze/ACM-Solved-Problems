#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
char s[MAX];
int pre[MAX],suf[MAX];
int main()
{
	int t,n,i,ans,f,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=0;i<=n+1;i++) pre[i]=suf[i]=0;
		f=0;
		for(i=3;i<=n;i++)
		{
			if(s[i-2]=='B'&&s[i-1]=='T'&&s[i]=='T') f=1;
			else if(s[i-1]=='T'&&s[i]=='B') pre[i]=f;
			else if(s[i-1]==s[i]) f=0;
		}
		f=0;
		for(i=n-2;i>=1;i--)
		{
			if(s[i]=='T'&&s[i+1]=='T'&&s[i+2]=='B') f=1;
			else if(s[i]=='B'&&s[i+1]=='T') suf[i]=f;
			else if(s[i]==s[i+1]) f=0;
		}
		l=INF;
		r=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='T')
			{
				l=min(l,i);
				r=max(r,i);
				ans=max(ans,r-l+1+pre[l-1]+suf[r+1]);
			}
			else
			{
				l=INF;
				r=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
