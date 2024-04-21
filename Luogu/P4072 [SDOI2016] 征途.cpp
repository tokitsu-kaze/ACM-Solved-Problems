#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3000+10;
struct convex_hull_trick
{
	#define type ll
	#define k_increase 1  // 0 or 1
	struct func_node{type y,k,x;}f[MAX];
	int q[MAX],l,r;
	void init(){l=r=0;}
	void add(int pos,type y,type k,type x)
	{
		/*
		(y-y[r])/(x-x[r])>(y[r]-y[r-1])/(x[r]-x[r-1])
		(y-y[r])*(x[r]-x[r-1])>(x-x[r])*(y[r]-y[r-1])
		*/
		while(r-l>1 && (y-f[q[r-1]].y)*(f[q[r-1]].x-f[q[r-2]].x)
					 <=(x-f[q[r-1]].x)*(f[q[r-1]].y-f[q[r-2]].y)) r--;
		q[r++]=pos;
		f[pos]={y,k,x};
	}
	int get_min_pos(type k)
	{
		/*
		k1=(y[ll]-y[ll-1])/(x[ll]-x[ll-1])
		k2=(y[ll+1]-y[ll])/(x[ll+1]-x[ll])
		k1 <= k < k2
		*/
		if(k_increase)
		{
			/*
			k_1 < k_2 < ... <k_n
			k1<=k -> (y[ll]-y[ll-1])<=k*(x[ll]-x[ll-1])
			*/
			while(r-l>1 && (f[q[l+1]].y-f[q[l]].y)
					   <=k*(f[q[l+1]].x-f[q[l]].x)) l++;
			return q[l];
		}
		else
		{
			// k<k2 -> k*(x[ll+1]-x[ll])<(y[ll+1]-y[ll])
			int ll,rr,mid;
			ll=l;
			rr=r-1;
			while(ll<rr)
			{
				mid=(ll+rr)>>1;
				if(k*(f[q[mid+1]].x-f[q[mid]].x)
				    <(f[q[mid+1]].y-f[q[mid]].y)) rr=mid;
				else ll=mid+1;
			}
			return q[ll];
		}
	}
	#undef type
	#undef k_increase
}convex[2];
/*
convex.init();
convex.add(pos,y,k,x);
convex.get_min_pos(k);
*/
ll sqr(ll x){return x*x;}
ll bit[MAX],dp[2][MAX];
int main()
{
	int n,m,i,j,k,x,f;
	scanf("%d%d",&n,&m);
	assert(m<=n);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		bit[i]=bit[i-1]+x;
	}
	f=0;
	dp[f][0]=0;
	convex[f].init();
	convex[f].add(0,dp[f][0]+sqr(bit[0]),2*bit[0],bit[0]);
	for(k=1;k<=m;k++)
	{
		f^=1;
		dp[f][0]=0;
		convex[f].init();
		convex[f].add(0,dp[f][0]+sqr(bit[0]),2*bit[0],bit[0]);
		for(i=1;i<=n;i++)
		{
			j=convex[f^1].get_min_pos(2*bit[i]);
			dp[f][i]=dp[f^1][j]+sqr(bit[i]-bit[j]);
			convex[f].add(i,dp[f][i]+sqr(bit[i]),2*bit[i],bit[i]);
		}
	}
	printf("%lld\n",-sqr(bit[n])+m*dp[f][n]);
	return 0;
}
/*
ans=-bit[n]^2+m*dp[n]

dp[i][k]=dp[j][k-1]+(bit[i]-bit[j])^2
dp[i][k]=dp[j][k-1]+bit[i]^2-2*bit[i]*bit[j]+bit[j]^2
dp[i][k]=bit[i]^2-2*bit[i]*bit[j]
dp[j][k-1]+bit[j]^2=2*bit[i]*bit[j]+(dp[i][k]-bit[i]^2)
y=dp[j][k-1]+bit[j]^2
k=2*bit[i]
x=bit[j]
*/
