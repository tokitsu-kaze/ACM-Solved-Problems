#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=1e9+7;
vector<int> colpos[MAX],colid[MAX];
int l[MAX],r[MAX],n,m;
pair<int,ll> cal(int id,int col)
{
	int c,x,y,z,tot,p;
	ll cnt;
	if(id>=1 && id<=m) tot=1;
	else tot=0;
	cnt=1;
	p=l[id];
	for(c=1;c<=n;c++)
	{
		x=y=z=0;
		for(auto &it:colid[c])
		{
			if(it==id) continue;
			if(l[it]<p && r[it]>p) z++;
			else if(l[it]<p) x++;
			else if(r[it]>p) y++;
		}
		if(c==col)
		{
			if(z+y>0)
			{
				tot++;
				cnt=cnt*(z+y);
			}
		}
		else
		{
			if(z>=2 || (z==1 && x+y>0))
			{
				tot+=2;
				cnt=cnt*z%mod*(z-1+x+y)%mod;
			}
			else if(z+x+y)
			{
				tot++;
				cnt=cnt*(2*z+x+y)%mod;
			}
		}
	}
	return {tot,cnt};
}
int main()
{
	int i,c,x,mx;
	ll cnt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		colpos[i].clear();
		colid[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c);
		colpos[c].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&c,&x);
		if(x>colpos[c].size()) continue;
		l[i]=colpos[c][x-1];
		r[i]=colpos[c][colpos[c].size()-x];
		colid[c].push_back(i);
	}
	l[0]=-1;
	auto res=cal(0,-1);
	mx=res.first;
	cnt=res.second;
	for(c=1;c<=n;c++)
	{
		for(auto &id:colid[c])
		{
			auto res=cal(id,c);
			if(res.first>mx)
			{
				mx=res.first;
				cnt=res.second;
			}
			else if(res.first==mx) cnt=(cnt+res.second)%mod;
		}
	}
	printf("%d %lld\n",mx,cnt);
	return 0;
}
/*
每种甜度最多选2头，一左一右。不同甜度互不影响。
考虑枚举放左边的第一头，以它为分界线。剩下的随便放，一定不重。
计算每种甜度有a头只能放左，b头只能放右，c头左右都行。
a和b只有一个有值。然后算一下怎么放即可。
注意算的时候当前颜色要判一下，以及左边不放的情况。
*/
