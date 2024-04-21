#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct convex_hull_trick
{
	#define type ll
	#define k_increase 0
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
ll t[MAX],f[MAX],dp[MAX],bitt[MAX],bitf[MAX];
int main()
{
	int n,i,j;
	ll s;
	scanf("%d",&n);
	scanf("%lld",&s);
	bitt[0]=bitf[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&t[i],&f[i]);
		bitt[i]=bitt[i-1]+t[i];
		bitf[i]=bitf[i-1]+f[i];
	}
	convex.init();
	dp[0]=0;
	convex.add(0,dp[0]-s*bitf[0],bitt[0],bitf[0]);
	for(i=1;i<=n;i++)
	{
		j=convex.get_mn_pos(bitt[i]);
		dp[i]=dp[j]+s*(bitf[n]-bitf[j])+(bitf[i]-bitf[j])*bitt[i];
		convex.add(i,dp[i]-s*bitf[i],bitt[i],bitf[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
/*
(f1+f2)*(s+t1+t2) + (f3)*(2*s+t1+t2+t3) + (f4+f5)*(3*s+t1+...+t5)

=(f1+...+f5)*s + (f3+f4+f5)*s + (f4+f5)*s
 + (f1+f2)*(t1+t2) + f3*(t1+t2+t3) + (f4+f5)*(t1+...+t5)


dp[i]=dp[j]+s*(bitf[n]-bitf[j])+(bitf[i]-bitf[j])*bitt[i])
dp[i]=dp[j]+s*bitf[n]-s*bitf[j]+bitf[i]*bitt[i]-bitf[j]*bitt[i]

(x,y) -> (j,dp[j])
dp[j]=dp[i]-s*bitf[n]+s*bitf[j]-bitf[i]*bitt[i]+bitf[j]*bitt[i]
dp[j]-s*bitf[j]=bitt[i]*bitf[j]+(dp[i]-s*bitf[n]-bitf[i]*bitt[i])
y=dp[j]-s*bitf[j]
k=bitt[i]
x=bitf[j]
b=(dp[i]-s*bitf[n]-bitf[i]*bitt[i])

*/
