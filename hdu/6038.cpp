////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-25 20:04:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6038
////Problem Title: 
////Run result: Accept
////Run time:764MS
////Run memory:6360KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX],b[MAX],cnt1[MAX],cnt2[MAX],res[MAX],flag[MAX];
int main()
{
	ll n,m,i,j,k1,k2,len,pos,ans,cas=1;
	while(~scanf("%lld%lld",&n,&m))
	{
		mem(cnt1,0);
		mem(cnt2,0);
		mem(res,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
		}
		mem(flag,0);
		k1=0;
		for(i=0;i<n;i++)
		{
			if(!flag[i])
			{
				len=0;
				pos=i;
				while(!flag[pos])
				{
					flag[pos]=1;
					pos=a[pos];
					len++;
				}
				cnt1[k1++]=len;
			}
		}
		mem(flag,0);
		k2=0;
		for(i=0;i<m;i++)
		{
			if(!flag[i])
			{
				len=0;
				pos=i;
				while(!flag[pos])
				{
					flag[pos]=1;
					pos=b[pos];
					len++;
				}
				cnt2[k2++]=len;
			}
		}
		for(i=0;i<k1;i++)
		{
			for(j=0;j<k2;j++)
			{
				if(cnt1[i]%cnt2[j]==0) res[i]+=cnt2[j];
			}
		}
		ans=1;
		for(i=0;i<k1;i++)
		{
			ans*=res[i];
			ans%=mod;
		}
		printf("Case #%lld: %lld\n",cas++,ans);
	}
	return 0;
}