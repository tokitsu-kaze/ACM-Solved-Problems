#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int lena,lenb,len,i,x,y;
	ll ans,sd;
	string a,b;
	cin>>x>>y;
	while(x>0)
	{
		a+=x%3+'0';
		x/=3;
	}
	while(y>0)
	{
		b+=y%3+'0';
		y/=3;
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	lena=a.size();
	lenb=b.size();
	len=max(lena,lenb);
	while(a.size()<len) a="0"+a;
	while(b.size()<len) b="0"+b;
	ans=0;
	sd=1;
	for(i=len-1;~i;i--)
	{
		ans+=(b[i]-a[i]+3)%3*sd;
		sd*=3;
	}
	printf("%lld\n",ans);
	return 0;
}
