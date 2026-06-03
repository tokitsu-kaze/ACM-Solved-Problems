#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int pre[MAX],nex[MAX];
int main()
{
	int T,n,k,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		nex[n+1]=INF;
		for(i=n;i;i--)
		{
			if(s[i]=='1') nex[i]=i;
			else nex[i]=nex[i+1];
		}
		ans=0;
		pre[0]=-INF;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1') pre[i]=i;
			else pre[i]=pre[i-1];
			if(s[i]=='0')
			{
				if(i-pre[i]>k && nex[i]-i>k)
				{
					s[i]='1';
					pre[i]=i;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
