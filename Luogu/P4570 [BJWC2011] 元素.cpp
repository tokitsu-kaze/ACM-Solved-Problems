#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Base
{
	#define type ll
	#define mx 60
	type d[mx+3];
	void init()
	{
		memset(d,0,sizeof(d));
	}
	bool insert(type x)
	{
		for(int i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type ask_max()
	{
		type res=0;
		for(int i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
		}
		return res;
	}
}bs;
struct node{ll x,y;}res[1010];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	bs.init();
	for(i=1;i<=n;i++) scanf("%lld%lld",&res[i].x,&res[i].y);
	sort(res+1,res+1+n,[&](node a,node b){
		return a.y>b.y;
	});
	ans=0;
	bs.init();
	for(i=1;i<=n;i++)
	{
		if(bs.insert(res[i].x)) ans+=res[i].y;
	}
	printf("%lld\n",ans);
	return 0;
}
