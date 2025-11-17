#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll h,d;
int ck(ll stp)
{
	ll cnt,seg,len,res;
	cnt=stp-d;
	res=0;
	seg=cnt+1;
	len=d/seg;
	res+=(d%seg)*(len+1);
	res+=(cnt+1)*(1+len)*len/2;
//	cout<<seg<<" "<<len<<" "<<res<<" "<<cnt<<endl;
	return res<h+cnt;
}
int main()
{
	int T;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&h,&d);
		l=d;
		r=3e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
