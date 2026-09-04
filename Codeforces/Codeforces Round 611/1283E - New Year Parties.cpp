#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX],now[MAX];
int main()
{
	int n,i,x,mn,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	memset(now,0,sizeof now);
	for(i=1;i<=n;i++)
	{
		if(!cnt[i]) continue;
		if(now[i-1]) now[i-1]+=cnt[i];
		else if(now[i]) now[i]+=cnt[i];
		else now[i+1]+=cnt[i];
	}
	mn=0;
	for(i=0;i<=n+1;i++) mn+=(now[i]>0);
	
	memset(now,0,sizeof now);
	for(i=1;i<=n;i++)
	{
		x=cnt[i];
		while(x>0)
		{
			if(!now[i-1]) now[i-1]++;
			else if(!now[i]) now[i]++;
			else now[i+1]++;
			x--;
		}
	}
	mx=0;
	for(i=0;i<=n+1;i++) mx+=(now[i]>0);
	
	printf("%d %d\n",mn,mx);
	return 0;
}
/*
最少就是优先往有的地方动；最多就是优先往前动。
*/
