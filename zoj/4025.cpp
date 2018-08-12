#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
map<int,int>mp;
int n,T,a[MAXN],b[MAXN],ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&b[i]);
		}
		mp.clear();
		ans=0;
		for(int i=1;i<=n;++i)
		{
			mp[a[i]-b[i]]++;
			ans=max(ans,mp[a[i]-b[i]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}