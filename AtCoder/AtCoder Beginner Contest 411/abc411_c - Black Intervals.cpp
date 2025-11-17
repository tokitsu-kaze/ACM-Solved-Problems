#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int n,q,x,i,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) a[i]=0;
	ans=0;
	while(q--)
	{
		scanf("%d",&x);
		if(!a[x])
		{
			if(x>1 && x<n)
			{
				if(a[x-1]==0 && a[x+1]==0) ans++;
				else if(a[x-1]==1 && a[x+1]==1) ans--;
			}
			else if(x==1)
			{
				if(a[x+1]==0) ans++;
			}
			else if(x==n)
			{
				if(a[x-1]==0) ans++;
			}
			a[x]=1;
		}
		else
		{
			if(x>1 && x<n)
			{
				if(a[x-1]==1 && a[x+1]==1) ans++;
				else if(a[x-1]==0 && a[x+1]==0) ans--;
			}
			else if(x==1)
			{
				if(a[x+1]==0) ans--;
			}
			else if(x==n)
			{
				if(a[x-1]==0) ans--;
			}
			a[x]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
