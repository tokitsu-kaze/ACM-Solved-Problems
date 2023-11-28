#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int f(ll x)
{
	if(x==0) return 1;
	if(x%3==0) return f(x/3)+1;
	return f(x-1)+1;
}
string gao(ll x)
{
	if(x<3) return to_string(x);
	return to_string(x%3)+gao(x/3);
}
int main()
{
	int t,ans,i;
	ll l,r,sd,now,tmp;
	string x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		if(l==r)
		{
			printf("%d\n",f(l));
			continue;
		}
		x=gao(l);
		y=gao(r);
	//	cout<<y<<endl;
		ans=y.size();
		for(auto &it:y) ans+=it-'0';
		if(x.size()<y.size()) ans=max(ans,(int)(x.size()+x.size()*2));
		sd=1;
		now=y[0]-'0';
		for(i=1;i<y.size();i++)
		{
			if(y[i]!='0')
			{
				tmp=r-now-1;
				if(tmp>=l) ans=max(ans,f(tmp));
			}
			sd*=3;
			now+=(y[i]-'0')*sd;
	//		printf("** %lld\n",tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}


