#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,i,ans,a[33],mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		if(mx==0)
		{
			puts("0");
			continue;
		}
		ans=1;
		for(i=1;i<n;i++)
		{
			if(a[i]-2*a[i+1]<0)
			{
				ans=-1;
				break;
			}
			ans=max(ans,a[i]-2*a[i+1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
做个差分，每次相邻的数的变化量其实就是 0<=a[i]-2*a[i+1]<=1，
操作数就是 max{a[i]-2*a[i+1]}。
*/
