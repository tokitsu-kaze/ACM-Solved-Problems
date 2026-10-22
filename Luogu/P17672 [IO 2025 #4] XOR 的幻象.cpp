#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
namespace FWT
{
	void fwt(vector<ll> &a,int n,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(v==1)
					{
						a[i+j]=x+y;
						a[i+j+d]=x-y;
					}
					else
					{
						a[i+j]=(x+y)/2;
						a[i+j+d]=(x-y)/2;
					}
				}
			}
		}
	}
	vector<ll> XOR(vector<ll> a,vector<ll> b)
	{
		int n,len;
		n=a.size();
		for(len=1;len<n;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		fwt(a,len,1);
		fwt(b,len,1);
		for(int i=0;i<len;i++) a[i]*=b[i];
		fwt(a,len,-1);
		return a;
	}
}
struct edge{int to,w;};
vector<edge> mp[MAX];
int s[MAX];
const int V=(1<<20);
void dfs(int x,int fa)
{
	for(auto &it:mp[x])
	{
		if(it.to==fa) continue;
		s[it.to]=s[x]^it.w;
		dfs(it.to,x);
	}
}
int main()
{
	int n,q,i,x,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		s[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	dfs(1,0);
	vector<ll> ta(V,0),tb,res;
	for(i=1;i<=n;i++) ta[s[i]]++;
	tb=ta;
	res=FWT::XOR(ta,tb);
	res[0]=(res[0]-n)/2;
	for(i=1;i<V;i++) res[i]/=2;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		printf("%lld\n",res[x]);
	 } 
	return 0;
}
/*
求树上路径 xor 权值为 i 的方案数。
f(a,b)=a 到 b 的 xor 权值，对于任意 (a,b)，f(a,b)=f(rt,a) xor f(rt,b)。
所以求出根到 i 的 xor，自己和自己做 fwt 即可。卷完结果除 2。
要注意卷出来的 res[0] 包含了 f(a,a)，要减掉 n 再除 2。
*/
