#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
char s[MAX];
int l[MAX],sum[MAX];
const int delta=1e6;
int main()
{
	int n,i,ans,now;
	scanf("%s",s+1);
	n=strlen(s+1);
	sum[delta]=0;
	memset(l,0,sizeof l);
	ans=0;
	for(i=1;i<=n;i++)
	{
		sum[i]=(s[i]=='G'?-1:1);
		sum[i]+=sum[i-1];
		now=sum[i]+delta;
		if(sum[i]==0) ans=i;
		else if(!l[now]) l[now]=i;
		else ans=max(ans,i-l[now]);
	}
	printf("%d\n",ans);
	return 0;
}
