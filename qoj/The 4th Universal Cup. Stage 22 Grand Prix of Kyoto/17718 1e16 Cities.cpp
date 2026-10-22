#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
struct dsu
{
	#define type ll
	unordered_map<type,type> pre,sum;
	type n;
	void init(type _n){pre.clear();n=_n;}
	type find(type x)
	{
		if(pre.count(x)) pre[x]=find(pre[x]);
		else return x;
		return pre[x];
	}
	bool merge(type a,type b)
	{
		if(a<0 || a>n || b<0 || b>n) return 0;
		type ra,rb;
		ra=find(a);
		rb=find(b);
		if(!sum.count(ra)) sum[ra]=a;
		if(!sum.count(rb)) sum[rb]=b;
		if(ra!=rb)
		{
			pre[ra]=rb;
			sum[rb]^=sum[ra];
			return 1;
		}
		return 0;
	}
	type ask_xorsum(type x)
	{
		x=find(x);
		if(sum.count(x)) return sum[x];
		else return x;
	}
	#undef type
}dsu;
int a,b;
void work(int g)
{
	int x,y,k;
	k=a+b/g;
	for(x=1;x*x<=k;x++)
	{
		if(k%x) continue;
		y=k/x;
		if(__gcd(x,y)!=1) continue;
		dsu.merge(1LL*x*g,1LL*y*g);
	}
}
int main()
{
	int i,q;
	ll x;
	scanf("%d%d",&a,&b);
	dsu.init(1e16);
	for(i=1;i*i<=b;i++)
	{
		if(b%i) continue;
		work(i);
		work(b/i);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld",&x);
		printf("%lld\n",dsu.ask_xorsum(x));
	}
	return 0;
}
/*
最重要的一步：将 i, j 用 gcd 表示。
设 i=x*g, j=y*g，其中 gcd(x,y)=1。则 lcm(i,j)=x*y*g。
代入原式：x*y*g=A*g+B -> g(x*y-A)=B。
可知 g 是 B 因数。枚举 g。
x*y=A+B/g，然后分解等式右边，求出 x,y。
发现边不是很多，直接对 i, j 离散化后连边，求出连通块。
做完了。感觉难度绿~青。
*/
