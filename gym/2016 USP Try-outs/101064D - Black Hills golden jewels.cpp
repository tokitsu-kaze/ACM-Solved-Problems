#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX],n;
ll cal(ll x)
{
	int i,j;
	ll res=0;
	i=1;
	j=n;
	while(i<j)
	{
		while(j>i && a[i]+a[j]>x) j--;
		if(a[i]+a[j]<=x) res+=j-i;
		i++;
	}
	return res;
}
int main()
{
	int i;
	ll k,l,r,mid;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=0;
	r=2e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(cal(mid)>=k) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}

