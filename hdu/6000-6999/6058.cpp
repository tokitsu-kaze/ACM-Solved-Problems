////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-02 15:00:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6058
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:14084KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e5+10;
const ll mod=1e9+7;
int read(ll &ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret;
}
ll a[MAX],next1[MAX],pre[MAX],pos[MAX];
int main()
{
	ll t,n,k,i,j,now,l,r;
	ll ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			next1[i]=i+1;
			pre[i]=i-1;
			pos[a[i]]=i;
		}
		next1[0]=1;
		pre[0]=-1;
		next1[n+1]=-1;
		ans=0;
		for(i=1;i<=n-k+1;i++)
		{
			l=r=now=pos[i];
			for(j=1;j<=k-1;)
			{
				if(pre[l]==-1) break;
				l=pre[l];
				j++;
			}
			for(;j<=k-1;j++)
			{
				r=next1[r];
			}
			while(l!=next1[now]&&r!=-1)
			{
	//			cout<<l<<" "<<r<<endl;
				ans+=i*(l-(pre[l]==-1?0:pre[l]))*((next1[r]==-1?r:next1[r])-r);
				l=next1[l];
				r=next1[r];
			}
			l=pre[now];
			r=next1[now];
			next1[l]=r;
			pre[r]=l;
	//		cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1000
5 2
1 2 3 4 5
5 2
5 4 3 2 1
5 2
5 3 2 1 4
6 2
5 6 4 2 1 3
5 2
3 1 4 2 5
10 9
6 2 3 10 5 1 7 8 9 4
*/