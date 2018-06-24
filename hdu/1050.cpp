////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 20:22:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1592KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
struct move1
{
	int r;
	int flag;
}a[411];
int cmp(move1 a,move1 b)
{
	return a.r<b.r;
}
int main()
{
	int t,n,s,e,i,cnt,ans;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			for(i=0;i<2*n;i++)
			{
				cin>>s>>e;
				if(s>e) swap(s,e);
				a[i].r=(s+1)/2;
				a[i].flag=1;
				i++;
				a[i].r=(e+1)/2;
				a[i].flag=-1;
			}
			sort(a,a+2*n,cmp);
			cnt=ans=0;
			for(i=0;i<2*n;i++)
			{
				cnt+=a[i].flag;
				if(cnt>ans) ans=cnt;
			}
			cout<<ans*10<<endl;
		}
	}
    return 0;
}
