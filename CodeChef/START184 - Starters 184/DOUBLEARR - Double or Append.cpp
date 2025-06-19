#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int T,n,i,j,op,len,mex;
	ll ans,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) cnt[i]=0;
		len=1;
		cnt[0]=1;
		mex=1;
		ans=0;
		vector<ll> res;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&op);
			if(op==1)
			{
				cnt[mex]++;
				mex++;
				ans+=len;
				len++;
			}
			else
			{
				ans*=2;
				sum=0;
				for(j=0;j<mex;j++)
				{
					ans+=cnt[j]*sum;
					sum+=cnt[j];
					cnt[j]*=2;
				}
				len*=2;
			}
			res.push_back(ans);
		}
		for(i=0;i<n;i++) printf("%lld%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}

