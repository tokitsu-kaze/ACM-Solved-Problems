////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 17:05:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4985
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:2460KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],flag[MAX];
int main()
{
	int n,i,temp;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			flag[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			flag[i]=1;
			temp=a[i];
			printf("(%d",i);
			while(!flag[temp])
			{
				flag[temp]=1;
				printf(" %d",temp);
				temp=a[temp];
			}
			printf(")");
		}
		puts("");
	}
	return 0;
}