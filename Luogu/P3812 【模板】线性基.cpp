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
int main()
{
	int n,i;
	ll x;
	scanf("%d",&n);
	bs.init();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		bs.insert(x);
	}
	printf("%lld\n",bs.ask_max());
	return 0;
}
