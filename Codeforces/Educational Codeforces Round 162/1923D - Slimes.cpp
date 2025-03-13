#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=998244353;
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
}rmq;
int a[MAX],n;
ll sum[MAX];
int ck(int l,int r,int x)
{
	assert(l<=r);
	if(l!=r && rmq.ask_min(l,r)==rmq.ask_max(l,r)) return 0;
	if(sum[r]-sum[l-1]>a[x]) return 1;
	return 0;
}
int call(int x)
{
	int l,r,mid;
	l=1;
	r=x-1;
	if(l>r) return INF;
	if(a[x-1]>a[x]) return 1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1,x-1,x)) l=mid+1;
		else r=mid;
	}
	if(ck(l,x-1,x)) return x-l;
	return INF;
}
int calr(int x)
{
	int l,r,mid;
	l=x+1;
	r=n;
	if(l>r) return INF;
	if(a[x+1]>a[x]) return 1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(x+1,mid,x)) r=mid;
		else l=mid+1;
	}
	if(ck(x+1,r,x)) return r-x;
	return INF;
}
int main()
{
	int T,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		rmq.work(n,a);
		for(i=1;i<=n;i++)
		{
			ans=INF;
			ans=min(ans,call(i));
			ans=min(ans,calr(i));
			if(ans==INF) ans=-1;
			printf("%d%c",ans," \n"[i==n]);
		}
	}
	return 0;
}
/*
1
5
2 3 2 2 1
*/
