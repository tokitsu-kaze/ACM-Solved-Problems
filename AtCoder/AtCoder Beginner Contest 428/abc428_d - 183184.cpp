#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll sq(ll x)
{
	ll res=sqrt(x+0.5);
	while(res*res<x) res++;
	while(res*res>x) res--;
	return res;
}
int main()
{
	int T,i;
	ll c,d,ans,l,r,up,sd;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&c,&d);
		string a=to_string(c);
		string b=to_string(c+d);
		up=stoll(a+b);
		r=c;
		sd=1;
		for(i=0;i<a.size();i++)
		{
			r=r*10+9;
			sd=sd*10;
		}
		r=min(r,up);
		l=stoll(a+a)+1;
		ans=sq(r)-sq(l-1);
		for(i=a.size()*2+1;i<=a.size()+b.size();i++)
		{
			l=c*sd*10+sd;
			r=min(up,r*10+9);
			if(l<=r) ans+=sq(r)-sq(l-1);
			sd*=10;
//			cout<<ans<<" "<<l<<" "<<r<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
