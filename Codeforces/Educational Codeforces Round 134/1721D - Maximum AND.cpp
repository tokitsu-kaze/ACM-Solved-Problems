#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,a[MAX],b[MAX];
int ck(int ans)
{
	int i,x;
	map<int,int> mp;
	for(i=1;i<=n;i++) mp[b[i]&ans]++;
	for(i=1;i<=n;i++)
	{
		x=((a[i]&ans)^ans);
		if(mp.count(x))
		{
			if(mp[x]>0) mp[x]--;
			else return 0;
		}
		else return 0;
	}
	return 1;
}
int main()
{
	int t,i,j,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=0;
		for(i=30;~i;i--)
		{
			if(ck(ans|(1<<i))) ans|=(1<<i);
		}
		printf("%d\n",ans);
	}
	return 0;
}

