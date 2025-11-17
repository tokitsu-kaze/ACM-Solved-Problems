#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char s[MAX];
int suf[MAX][2];
int main()
{
	int T,n,i,ans,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(suf[n+1],0,sizeof suf[n+1]);
		for(i=n;i;i--)
		{
			suf[i][0]=suf[i+1][0];
			suf[i][1]=suf[i+1][1];
			suf[i][s[i]-'0']++;
		}
		ans=INF;
		cnt=0;
		for(i=0;i<=n;i++)
		{
			ans=min(ans,cnt+suf[i+1][0]);
			if(s[i+1]=='1') cnt++;
		}
		cnt=0;
		for(i=0;i<=n;i++)
		{
			ans=min(ans,cnt+suf[i+1][1]);
			if(s[i+1]=='0') cnt++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
