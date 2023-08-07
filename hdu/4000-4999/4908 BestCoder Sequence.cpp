////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-18 16:51:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4908
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:2136KB
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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=40000+10;
const ll mod=1e6;
int cnt[2*MAX];
int sum[MAX];
int main()
{
	int n,m,i,a,ans,pos;
	while(~scanf("%d%d",&n,&m))
	{
		ans=0;
		mem(cnt,0);
		mem(sum,0);
		for(i=1;i<=n;i++)
		{
			sum[i]=sum[i-1];
			scanf("%d",&a);
			if(a>m) sum[i]++;
			else if(a<m) sum[i]--;
			else if(a==m) pos=i;
		}
		for(i=0;i<pos;i++)
		{
			cnt[sum[i]+MAX]++;
		}
		for(i=pos;i<=n;i++)
		{
			ans+=cnt[sum[i]+MAX];
		}
		printf("%d\n",ans);
	}
	return 0;
}
