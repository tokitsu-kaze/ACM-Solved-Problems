#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cal(ll x)
{
	ll now;
	int i,cnt,flag;
	cnt=0;
	flag=0;
	now=10;
	for(i=0;;i++)
	{
		if(x%now==0) cnt++;
		else
		{
			if(x%now==5*now/10) flag=1;
			break;
		}
		now=now*10;
	}
//	printf("%lld %d\n",x,2*(to_string(x).size()-cnt)-flag);
	return 2*(to_string(x).size()-cnt)-flag;
}
int main()
{
	int T,i;
	ll ans,x,now,res,l,r,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&l,&r);
		ans=cal(l);
		x=l;
		now=1;
		while(now<=r)
		{
			tmp=(now-l%now)%now;
			if(l+tmp<=r)
			{
				res=cal(l+tmp);
				if(res<ans)
				{
					ans=res;
					x=l+tmp;
				}
			}
			tmp=5*now-l%(now*10);
			if(tmp>=0 && l+tmp<=r)
			{
				res=cal(l+tmp);
				if(res<ans)
				{
					ans=res;
					x=l+tmp;
				}
			}
			now=now*10;
		}
		printf("%d\n",x);
	}
	return 0;
}
