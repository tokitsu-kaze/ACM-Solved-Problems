////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-25 20:37:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6168
////Problem Title: 
////Run result: Accept
////Run time:748MS
////Run memory:8116KB
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
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=125250+10;
const ll mod=1e9+7;
int a[MAX];
map<int,int> mp;
int main()
{
	int i,j,cnt,n,ans[511],x;
	while(~scanf("%d",&n))
	{
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(!mp[a[i]])
			{
				for(j=0;j<cnt;j++)
				{
					mp[ans[j]+a[i]]++;
				}
				ans[cnt++]=a[i];
			}
			else mp[a[i]]--;
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			i==cnt-1?printf("%d\n",ans[i]):printf("%d ",ans[i]);
		}
	}
	return 0;
}