#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int n,k,a[MAX],b[MAX];
ll gao1()
{
	int i,mx;
	mx=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]) mx=max(mx,a[i]);
	}
	if(mx==0) return 0;
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=mx) res.push_back(a[i]);
	}
	while(res.size()<n-1) res.push_back(mx);
	sort(res.begin(),res.end());
	return 1LL*mx+k+res[n/2-1];
}
int ck(ll x,vector<int> &ra,vector<int> &rb)
{
	int i,cnt;
	ll now;
	cnt=0;
	for(auto &it:rb)
	{
		if(it<x) cnt++;
	}
	for(auto &it:ra)
	{
		if(it<x) cnt++;
	}
	if(cnt<n/2) return 1;
	if(cnt>=n/2)
	{
		now=0;
		for(i=ra.size()-1;~i;i--)
		{
			if(ra[i]<x)
			{
				now+=x-ra[i];
				cnt--;
				if(cnt<n/2) return now<=k;
			}
		}
	}
	return 0;
}
ll gao2()
{
	int i,mx,f;
	ll l,r,mid;
	mx=0;
	for(i=1;i<=n;i++)
	{
		if(!b[i]) mx=max(mx,a[i]);
	}
	if(mx==0) return 0;
	vector<int> ra,rb;
	f=1;
	for(i=1;i<=n;i++)
	{
		if(b[i]) ra.push_back(a[i]);
		else
		{
			if(a[i]==mx)
			{
				if(f) f=0;
				else rb.push_back(a[i]);
			}
			else rb.push_back(a[i]);
		}
	}
	sort(ra.begin(),ra.end());
	sort(rb.begin(),rb.end());
	l=1;
	r=2e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1,ra,rb)) l=mid+1;
		else r=mid;
	}
	return l+mx;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		printf("%lld\n",max(gao1(),gao2()));
	}
	return 0;
}
