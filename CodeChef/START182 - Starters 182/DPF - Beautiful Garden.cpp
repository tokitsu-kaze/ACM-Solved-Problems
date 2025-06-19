#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int now,delta;}a[12];
int main()
{
	int T,n,k,d,i,j,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].delta);
			a[i].now=1;
		}
		sort(a+1,a+1+n,[](node x,node y){
			return x.delta<y.delta;
		});
		ans=0;
		for(i=1;i<=d;i++)
		{
			now=0;
			for(j=1;j<=n;j++)
			{
				if(a[j].now<=i) now++;
			}
			for(j=1;j<=n;j++)
			{
				if(a[j].now<=i && now-1>=k)
				{
					now--;
					a[j].now+=a[j].delta;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
