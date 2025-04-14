#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,k,m,i,j,a[55],ans,sum,now,cnt,tmp;
	scanf("%d%d%d",&n,&k,&m);
	sum=0;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+k);
	ans=0;
	for(i=0;i<=n;i++)
	{
		cnt=i*(k+1);
		now=m-i*sum;
		if(now<0) break;
		for(j=1;j<=k;j++)
		{
			tmp=min(n-i,now/a[j]);
			cnt+=tmp;
			now-=tmp*a[j];
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
