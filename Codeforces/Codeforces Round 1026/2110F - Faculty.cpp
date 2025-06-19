#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX],res[MAX];
int main()
{
	int T,n,i,j,ans,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		res[1]=ans=0;
		mx=a[1];
		for(i=2;i<=n;i++)
		{
			if(a[i]>=2*mx)
			{
				mx=a[i];
				for(j=1;j<i;j++) ans=max(ans,mx%a[j]+a[j]%mx);
			}
			else ans=max(ans,mx%a[i]+a[i]%mx);
			mx=max(mx,a[i]);
			res[i]=ans;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
