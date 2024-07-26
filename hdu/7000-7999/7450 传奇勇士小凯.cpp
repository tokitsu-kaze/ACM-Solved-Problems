#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct fraction
{
	#define type ll
	type fz,fm;
	static void simplify(type &x,type &y)
	{
		if(y<0)
		{
			x*=-1;
			y*=-1;
		}
		type g=__gcd(abs(x),abs(y));
		x/=g,y/=g;
	}
	fraction(){fz=0,fm=1;}
	fraction(type x){fz=x,fm=1;}
	fraction(type _fz,type _fm)
	{
		fz=_fz,fm=_fm;
		simplify(fz,fm);
	}
	static type lcm(type x,type y){return x/__gcd(x,y)*y;}
	friend fraction operator +(const fraction &x,const fraction &y)
	{
		fraction res;
		res.fm=lcm(x.fm,y.fm);
		res.fz=x.fz*(res.fm/x.fm)+y.fz*(res.fm/y.fm);
		simplify(res.fz,res.fm);
		if(res.fz==0) res.fm=1;
		return res;
	}
	fraction operator +(const type &x)const{return (*this)+fraction(x);}
	fraction operator -(const fraction &x)const{return (*this)+fraction(-x.fz,x.fm);}
	fraction operator -(const type &x)const{return (*this)+fraction(-x);}
	friend fraction operator *(const fraction &x,const fraction &y)
	{
		fraction res;
		res.fz=x.fz*y.fz;
		res.fm=x.fm*y.fm;
		simplify(res.fz,res.fm);
		if(res.fz==0) res.fm=1;
		return res;
	}
	fraction operator *(const type &x)const{return (*this)*fraction(x);}
	fraction operator /(const fraction &x)const{return (*this)*fraction(x.fm,x.fz);}
	fraction operator /(const type &x)const{return (*this)*fraction(1,x);}
	friend bool operator <(const fraction &x,const fraction &y)
	{
		type t=lcm(x.fm,y.fm);
		return x.fz*(t/x.fm)<y.fz*(t/y.fm);
	}
	friend bool operator ==(const fraction &x,const fraction &y)
	{
		return x.fz==y.fz&&x.fm==y.fm;
	}
	#undef type
};
vector<int> mp[MAX];
int p[MAX];
fraction mx;
void dfs(int x,int fa,fraction now)
{
	now=now+fraction(15,p[x]);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,now);
	}
	mx=max(mx,now);
}
int main()
{
	int t,n,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		mx=fraction(0);
		dfs(1,0,fraction(0));
		printf("%lld/%lld\n",mx.fz,mx.fm);
	}
	return 0;
}
