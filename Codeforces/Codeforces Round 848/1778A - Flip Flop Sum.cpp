#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		f=0;
		for(i=1;i<n && !f;i++)
		{
			if(a[i]==-1 && a[i+1]==-1)
			{
				f=1;
				a[i]*=-1;
				a[i+1]*=-1;
			}
		}
		for(i=1;i<n && !f;i++)
		{
			if(a[i]*a[i+1]==-1)
			{
				f=1;
				a[i]*=-1;
				a[i+1]*=-1;
			}
		}
		for(i=1;i<n && !f;i++)
		{
			if(a[i]==1 && a[i+1]==1)
			{
				f=1;
				a[i]*=-1;
				a[i+1]*=-1;
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}
