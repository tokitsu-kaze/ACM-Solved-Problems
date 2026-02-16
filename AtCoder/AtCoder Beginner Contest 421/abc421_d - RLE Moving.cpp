#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll a,b,c,d,x[MAX],y[MAX];
char s[MAX],t[MAX];
void move(ll &x,ll &y,char op,ll k)
{
	if(op=='L') y-=k;
	else if(op=='R') y+=k;
	else if(op=='U') x-=k;
	else if(op=='D') x+=k;
}
int ck(int k,char xx,char yy)
{
	ll ta,tb,tc,td;
	ta=a;
	tb=b;
	tc=c;
	td=d;
	move(ta,tb,xx,k);
	move(tc,td,yy,k);
	return abs(ta-tc)+abs(tb-td);
}
ll cal(char xx,char yy,ll k)
{
	ll l,r,lm,rm,tl,tr;
	if(xx==yy)
	{
		if(a==c && b==d) return k;
		return 0;
	}
	l=1;
	r=k;
	while(l<r)
	{
		lm=l+(r-l)/3;
		rm=r-(r-l)/3;
		tl=ck(lm,xx,yy);
		tr=ck(rm,xx,yy);
		if(tl>tr) l=lm+1;
		else r=rm-1;
	}
	if(ck(l,xx,yy)==0) return 1;
	return 0;
}
int main()
{
	int i,m,l;
	ll n,pm,pl,mn,ans;
	char ch[2];
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	scanf("%lld%d%d",&n,&m,&l);
	for(i=1;i<=m;i++)
	{
		scanf("%s%lld",ch,&x[i]);
		s[i]=ch[0];
	}
	for(i=1;i<=l;i++)
	{
		scanf("%s%lld",ch,&y[i]);
		t[i]=ch[0];
	}
	pm=pl=1;
	ans=0;
	while(pm<=m)
	{
		mn=min(x[pm],y[pl]);
		x[pm]-=mn;
		y[pl]-=mn;
		ans+=cal(s[pm],t[pl],mn);
		move(a,b,s[pm],mn);
		move(c,d,t[pl],mn);
		if(x[pm]==0) pm++;
		if(y[pl]==0) pl++;
	}
	printf("%lld\n",ans);
	return 0;
}
