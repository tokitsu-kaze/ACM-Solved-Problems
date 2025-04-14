#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,a[105],res[105],r,ok,mx,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(res,-1,sizeof res);
	r=1;
	while(1)
	{
		ok=1;
		mx=0;
		for(i=1;i<=n;i++)
		{
			if(res[i]==-1)
			{
				mx=max(mx,a[i]);
				ok=0;
			}
		}
		if(ok) break;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(res[i]==-1)
			{
				if(a[i]==mx)
				{
					cnt++;
					res[i]=r;
				}
			}
		}
		r+=cnt;
	}
	for(i=1;i<=n;i++) printf("%d\n",res[i]);
	return 0;
}
