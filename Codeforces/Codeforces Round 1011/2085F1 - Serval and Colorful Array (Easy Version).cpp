#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int a[MAX],l[MAX],r[MAX],res[MAX];
int main()
{
	int T,n,k,i,p,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=INF;
		for(p=1;p<=n;p++)
		{
			for(i=1;i<=k;i++) l[i]=r[i]=n+1;
			for(i=1;i<=p;i++) l[a[i]]=min(l[a[i]],p-i);
			for(i=p;i<=n;i++) r[a[i]]=min(r[a[i]],i-p);
			now=0;
			for(i=1;i<=k;i++)
			{
				now+=l[i];
				res[i]=r[i]-l[i];
			}
			sort(res+1,res+1+k);
			for(i=1;i<=(k+1)/2;i++) now+=res[i];
			ans=min(ans,now);
		}
		for(i=1;i<=k;i++) ans-=abs(i-(k+1)/2);
		printf("%d\n",ans);
	}
	return 0;
}
