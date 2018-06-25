////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-09 20:31:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 6025
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2128KB
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
const double eps=1e-12;
const int MAX=100000+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,t,i,j,flag,ans,cnt;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a,a+n);
			flag=0;
			for(j=0;i<2;j++)
			{
				cnt=flag;
				for(i=n-1;i>0;i--)
				{
					if(a[i]%a[j]) cnt++;
					if(cnt>1)
					{
						flag+=i+1;
						break;
					}
				}
			}
			if(flag==3) ans=1;
			else if(flag==2) ans=a[0];
			else ans=a[1];
			printf("%d\n",ans);
		}
	}
	return 0;
}