#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct node
{
	ll v;
	int pos;
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
};
int n,k,d,x[MAX],s[MAX];
ll dp[MAX];
int ck(int g)
{
	int l,r,len,i,j;
	ll ans;
	l=max(1,d-g);
	r=d+g;
	priority_queue<node> q;
	ans=0;
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	j=0;
	for(i=1;i<=n;i++)
	{
		while(j<i && x[j]<=x[i]-l)
		{
			if(dp[j]!=-1) q.push({dp[j],x[j]});
			j++;
		}
		while(!q.empty() && q.top().pos<x[i]-r) q.pop();
		if(q.empty()) continue;
		dp[i]=q.top().v+s[i];
		ans=max(ans,dp[i]);
	//	printf("x[i]:%d dp[i]:%lld\n",x[i],dp[i]);
	}
	return ans>=k;
}
int main()
{
	int l,r,mid,i;
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&s[i]);
	x[0]=s[0]=0;
	l=0;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	if(ck(l)) printf("%d\n",l);
	else puts("-1");
	return 0;
}
