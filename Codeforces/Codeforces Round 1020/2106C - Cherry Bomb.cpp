#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,k,i,x,ok,mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			if(b[i]==-1) continue;
			s.insert(a[i]+b[i]);
		}
		if(s.size()>1)
		{
			puts("0");
			continue;
		}
		if(s.size()==1)
		{
			ok=1;
			x=*s.begin();
			for(i=1;i<=n;i++)
			{
				if(b[i]==-1) b[i]=x-a[i];
				if(b[i]>=0 && b[i]<=k);
				else ok=0;
			}
			printf("%d\n",ok);
			continue;
		}
		mx=-1;
		mn=k+1;
		for(i=1;i<=n;i++)
		{
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		printf("%d\n",k-(mx-mn)+1);
	}
	return 0;
}
