#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const int mod=1e9+7;
int main()
{
	int T,n,x,i,a,cnt[2],tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			cnt[a&1]++;
		}
		if(cnt[1]==0)
		{
			puts("No");
			continue;
		}
		cnt[1]--;
		x--;
		tmp=min(cnt[1]/2*2,x/2*2);
		x-=tmp;
		if(cnt[0]<x) puts("No");
		else puts("Yes");
	}
	return 0;
}
