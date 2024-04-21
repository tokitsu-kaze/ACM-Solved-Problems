#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e4+10;
struct convex_hull_trick
{
	#define type ll
	#define k_increase 1
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
	int get_mn_pos(type k)
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
}convex;
/*
convex.init();
convex.add(pos,y,k,x);
convex.get_mn_pos(k);
*/
ll sqr(ll x){return x*x;}
ll w[MAX],dp[MAX];
int main()
{
	int n,i,j,x,L;
	ll c;
	scanf("%d%d",&n,&L);
	c=L+1;
	w[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		w[i]=w[i-1]+x+1;
	}
	convex.init();
	dp[0]=0;
	convex.add(0,dp[0]+sqr(w[0])+2*c*w[0],2*w[0],w[0]);
	for(i=1;i<=n;i++)
	{
		j=convex.get_mn_pos(2*w[i]);
		dp[i]=dp[j]+sqr(w[i]-w[j]-c);
		convex.add(i,dp[i]+sqr(w[i])+2*c*w[i],2*w[i],w[i]);
	//	printf("%d %d %lld\n",i,j,dp[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
/*
dp[i]=dp[j-1]+((bit[i]-bit[j-1]+i-j)-L)^2
dp[i]=dp[j-1]+((bit[i]+i)-(bit[j-1]+(j-1))-L-1)^2
dp[i]=dp[j]+((bit[i]+i)-(bit[j]+j)-L-1)^2

c=L+1
w[i]=bit[i]+i

dp[i]=dp[j]+(w[i]-w[j]-c)*(w[i]-w[j]-c)
dp[i]=dp[j]
	+w[i]^2-w[i]*w[j]-c*w[i]
	-w[i]*w[j]+w[j]^2+c*w[j]
	-c*w[i]+c*w[j]+c^2

dp[j]=2*w[i]*w[j]+2*c*w[i]-2*c*w[j]+(dp[i]-w[i]^2-w[j]^2-c^2)
dp[j]+w[j]^2+2*c*w[j]=2*w[i]*w[j]+(dp[i]+2*c*w[i]-w[i]^2-c^2)
y=dp[j]+w[j]^2+2*c*w[j]
k=2*w[i]
x=w[j]
*/
