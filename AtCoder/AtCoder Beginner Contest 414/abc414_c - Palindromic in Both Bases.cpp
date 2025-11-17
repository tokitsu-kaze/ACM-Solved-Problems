#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int a;
ll n,ans;
void ck(string s)
{
	ll t,x;
	x=stoll(s);
	t=x;
	if(x>n) return;
	string now="";
	while(x>0)
	{
		now+='0'+x%a;
		x/=a;
	}
	string rev=now;
	reverse(rev.begin(),rev.end());
	if(rev==now) ans+=t;
}
int main()
{
	ll now;
	scanf("%d%lld",&a,&n);
	ans=0;
	for(now=1;now<=1e6;now++)
	{
		string tmp=to_string(now);
		string rev=tmp;
		string rev2=tmp;
		reverse(rev.begin(),rev.end());
		rev2.pop_back();
		reverse(rev2.begin(),rev2.end());
		ck(tmp+rev);
		ck(tmp+rev2);
	}
	printf("%lld\n",ans);
	return 0;
}
