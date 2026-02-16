#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cnt[MAX];
int main()
{
	int n,q,i,x,y,l,ans;
	memset(cnt,0,sizeof cnt);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) cnt[i]=1;
	l=1;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(l>x)
		{
			puts("0");
			continue;
		}
		ans=0;
		for(i=l;i<=x;i++)
		{
			ans+=cnt[i];
			cnt[y]+=cnt[i];
			cnt[i]=0;
		}
		l=x+1;
		printf("%d\n",ans);
	}
	return 0;
}
