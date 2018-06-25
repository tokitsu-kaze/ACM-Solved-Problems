////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-20 10:14:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6158
////Problem Title: 
////Run result: Accept
////Run time:1372MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int t,i,n;
	double r1,r2,r,ans,rn;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&r1,&r2);
		if(r1<r2) swap(r1,r2);
		scanf("%d",&n);
		ans=0;
		r=r2/r1;
		for(i=0;i<(n+1)/2;i++)
		{
			rn=(1-r)*r/((i*(1-r))*(i*(1-r))+r)*r1;
			if(rn<eps) break;
			if(i==0) ans+=rn*rn*PI;
			else ans+=2*rn*rn*PI;
		}
		rn=(1-r)*r/((i*(1-r))*(i*(1-r))+r)*r1;
		if(n%2==0) ans+=rn*rn*PI;
		printf("%.5lf\n",ans);
	}
	return 0;
}
/*
2
5 4
10000000

*/