#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=1e9+7;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmx[LOG][N],pmn[LOG][N];
	int pmax(const int &a,const int &b){return v[a]>v[b]?a:b;}
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmx[0][i]=pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmx[j][i]=pmax(pmx[j-1][i],pmx[j-1][i+bin[j-1]]);
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[t][l],pmx[t][r-bin[t]+1]);
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_max(int l,int r){return v[ask_pmax(l,r)];}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}st;
int a[MAX],n;
ll dfs(int l,int r)
{
	if(l>r) return 0;
	if(l==r) return 1;
	int p=st.ask_pmin(l,r);
	ll dpl,dpr,dpx;
	dpl=dfs(l,p-1);
	dpr=dfs(p+1,r);
	dpx=(dpl+1)*(dpr+1)%mod;
	if(l!=1) dpx=(dpx+dpr)%mod;
	if(r!=n) dpx=(dpx+dpl)%mod;
	return dpx;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	st.work(n,a);
	printf("%lld\n",dfs(1,n));
	return 0;
}
/*
发现跟笛卡尔树有关。
考虑建出笛卡尔树，进行树形dp。
dp[x] 表示子树 x，非空的方案数。讨论当前点删不删：
不删：子树任意组合，可以为空；
删：要删掉这个点，其中一侧子树必须为空，并且另一侧要求有数。
*/
