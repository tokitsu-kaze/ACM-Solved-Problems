#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int T,n,k,i,j,mex;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n+1;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		mex=0;
		while(cnt[mex]>0) mex++;
		for(j=0;j<10 && k>0;j++)
		{
			k--;
			for(i=1;i<=n;i++)
			{
				if(a[i]<mex)
				{
					if(cnt[a[i]]>1) a[i]=mex;
				}
				else a[i]=mex;
			}
			for(i=0;i<=n+1;i++) cnt[i]=0;
			for(i=1;i<=n;i++) cnt[a[i]]++;
			mex=0;
			while(cnt[mex]>0) mex++;
			if(k%2==0 && j>5) break;
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}
