#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int T,n,k,i,x,mex,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		mex=0;
		while(cnt[mex]) mex++;
		if(mex<=k)
		{
			ans=0;
			while(mex<k)
			{
				if(!cnt[mex])
				{
					if(cnt[k]>0) cnt[k]--;
					ans++;
				}
				mex++;
			}
			printf("%d\n",ans+cnt[k]);
		}
		else printf("%d\n",cnt[k]);
	}
	return 0;
}
