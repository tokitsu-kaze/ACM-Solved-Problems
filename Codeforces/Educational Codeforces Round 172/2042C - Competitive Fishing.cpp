#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int suf[MAX];
char s[MAX];
int main()
{
	int T,n,k,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		suf[n+1]=0;
		for(i=n;i;i--)
		{
			suf[i]=suf[i+1];
			if(s[i]=='1') suf[i]++;
			else suf[i]--;
		}
		sort(suf+2,suf+1+n);
		ans=0;
		for(i=n;i>1;i--)
		{
			if(suf[i]<=0) break;
			k-=suf[i];
			ans++;
			if(k<=0) break;
		}
		if(k>0) puts("-1");
		else printf("%d\n",ans+1);
	}
	return 0;
}
