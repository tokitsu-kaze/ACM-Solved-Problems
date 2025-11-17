#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
void bf()
{
	int c[111],d[111],vis[111],dp[111][2];
	int T,n,m,v,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&v);
		memset(vis,0,sizeof vis);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c[i],&d[i]);
			vis[c[i]]=1;
		}
		memset(dp,0,sizeof dp);
		if(vis[1]) dp[1][1]=1;
		else dp[1][0]=1;
		for(i=2;i<=n;i++)
		{
			if(vis[i])
			{
				dp[i][1]=v*v*dp[i-1][0]+(v*(v-1)+1)*dp[i-1][1];
				/*
				当前这个必须是确定的
				- 前一个不确定的话，总能合法，任选；
				- 前一个确定了，这个也要确定，
				  要么前一个不选确定的那个值，当前这个任选
				  要么前一个选，那只有 1 种
				*/
			}
			else
			{
				dp[i][0]=v*v*dp[i-1][0]+(v*(v-1))*dp[i-1][1];
				/*
				当前这个不确定
				- 前一个也不确定，任选
				- 前一个确定，那就不能选确定那个，当前这个任选 
				*/
				dp[i][1]=v*dp[i-1][1];
				/*
				当前这个确定，前一个必须是确定的，那么
				前一个有 1 种情况，当前有 v 种情况 
				*/
			}
		}
		printf("%d\n",dp[n][0]+dp[n][1]);
	}
}
const int mod=1e9+7;
struct Matrix
{
	static const int N=2;
	int n;
	ll c[N][N];
	Matrix(){}
	Matrix(int _n,ll v=0)
	{
		int i,j;
		n=_n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	void init_identity_matrix() {for(int i=0;i<n;i++) c[i][i]=1;}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matqpow(Matrix a,ll b)
{
	Matrix res(a.n);
	res.init_identity_matrix();
	while(b>0)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
//	freopen("assign3.in","r",stdin);
//	bf();
	int T,n,m,v,i,c,d,ok,lst,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&v);
		map<int,int> mp;
		ok=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c,&d);
			if(mp.count(c))
			{
				if(mp[c]!=d) ok=0;
			}
			else mp[c]=d;
		}
		if(!ok)
		{
			puts("0");
			continue;
		}
		
		Matrix c0(2),c1(2),now(2);
		
		c0.c[0][0]=1LL*v*v%mod;
		c0.c[1][0]=1LL*v*(v-1)%mod;
		c0.c[1][1]=v;
		
		c1.c[0][1]=1LL*v*v%mod;
		c1.c[1][1]=(1LL*v*(v-1)+1)%mod;
		
		if(mp.count(1)) now.c[0][1]=1;
		else now.c[0][0]=1;
		mp.erase(1);
		lst=1;
		for(auto &it:mp)
		{
			p=it.first;
			now=now*matqpow(c0,p-lst-1);
			now=now*c1;
			lst=p;
		}
		if(!mp.count(n)) now=now*matqpow(c0,n-lst);
		printf("%lld\n",(now.c[0][0]+now.c[0][1])%mod);
	}
	return 0;
}
/*
1-5，25分：O(T*2^n*n)暴力是不是很好做的。 
6-9，m=1，20分：直接算，快速幂。
10-12，性质 A，15分：也比较好做吧
如果会写 dp，能拿下 13 14 17 18，20分。
 

先判无解，有 ci=cj,di!=dj 的情况是无解
考虑到 di 并不是很重要，可以把情况看作相邻两个：
? ?
? x
x ?
x x
这 4 种。 
研究一下样例 2 的第 4 组，发现直接算多出两个5*5不知道怎么来的 
连起来的时候可能有连锁反应，考虑 dp
dp完了很自然想到矩乘 

[f0 f1]

位置 i 不确定
v*v       0
v*(v-1)   v

位置 i 确定
0   v*v
0   v*(v-1)+1


1
10 5 2
2 2
3 2
4 2
7 2
10 2

? x x x ? ? x ? ? x

*/

