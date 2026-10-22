#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		swap(a[n-1],a[1]);
		vector<int> tmp[2];
		for(i=2;i<n;i++) tmp[a[i]&1].push_back(a[i]);
		for(i=2;i<n;i++)
		{
			a[i]=-1;
			if(a[i-1]&1)
			{
				if(tmp[0].size())
				{
					a[i]=tmp[0].back();
					tmp[0].pop_back();
				}
			}
			if(a[i]==-1)
			{
				for(j=1;j>=0;j--)
				{
					if(tmp[j].size())
					{
						a[i]=tmp[j].back();
						tmp[j].pop_back();
						break;
					}
				}
			}
		}
		ans=0;
		for(i=1;i<n;i++) ans+=(a[i]+a[i+1])/2;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
大的放两边，奇数尽量不要相邻？
*/
