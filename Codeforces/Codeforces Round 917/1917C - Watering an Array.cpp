#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],v[MAX];
int main()
{
	int T,n,k,d,i,j,cnt,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&d);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=k;i++) scanf("%d",&v[i]);
		now=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==i) now++;
		}
		ans=0;
		cnt=0;
		for(i=1;i<=k;)
		{
			cnt++;
			if(cnt>d) break;
			if(n+(d-cnt)/2<ans) break;
			now=0;
			for(j=1;j<=n;j++)
			{
				if(a[j]==j) now++;
			}
			ans=max(ans,now+(d-cnt)/2);
			for(j=1;j<=v[i];j++) a[j]++;
			if(i==k) i=1;
			else i++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
