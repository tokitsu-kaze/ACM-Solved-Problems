////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 18:54:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4070
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:2380KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
struct cell
{
	int n,v;
}a[100010];
int cmp(cell a,cell b)
{
	if(a.v==b.v) return a.n>b.n;
	return a.v>b.v;
}
int main()
{
    int n,i,t,temp,ans,cas;
    while(cin>>t)
    {
		cas=1;
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i].n,&a[i].v);
			}
			sort(a,a+n,cmp);
			ans=temp=0;
			for(i=0;i<n;i++)
			{
				temp+=a[i].n;
				ans=max(ans,temp+a[i].v);
			}
			printf("Case %d: %d\n",cas++,ans);
		}
    }
    return 0;
}