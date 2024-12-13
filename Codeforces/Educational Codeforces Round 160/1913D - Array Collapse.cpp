#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int mod=998244353;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmn[LOG][N];
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}rmq;
int a[MAX],n;
ll dfs(int l,int r)
{
	if(l>r) return 1LL;
	if(l==r) return 2LL;
	int p=rmq.ask_pmin(l,r);
	ll ls=dfs(l,p-1);
	ll rs=dfs(p+1,r);
	ll tmp=0;
	if(l!=1) tmp+=rs;
	if(r!=n) tmp+=ls;
	if(l!=1 && r!=n) tmp--;
	if(tmp<0) tmp+=mod;
//	printf("%d %d %lld %lld %lld\n",l,r,ls,rs,tmp);
	return (ls*rs+tmp)%mod;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==1)
		{
			puts("1");
			continue;
		}
		rmq.work(n,a);
		printf("%lld\n",dfs(1,n));
	}
	return 0;
}
/*
1
4
1 3 4 2

1
1 2
1 3 2
1 4 2
1 3 4 2
*/
